#ifndef TYPE_TRAITS_TPP
#define TYPE_TRAITS_TPP
#include <iostream>

template <typename T, T val>
struct integral_constant
{
    using type = T;
    static constexpr type value = val;

    operator type() const
    {
        return value;
    }

    type operator()() const
    {
        return value;
    }
};

template <bool val>
struct bool_constant : integral_constant<bool, val>
{
};

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template <typename T, typename U>
struct is_same : false_type
{
};

template <typename T>
struct is_same<T, T> : true_type
{
};

template <typename T, typename U>
inline constexpr bool is_same_v = is_same<T, U>::value;

template <typename T>
struct remove_const
{
    using type = T;
};

template <typename T>
struct remove_const<const T>
{
    using type = T;
};

template <typename T>
struct remove_volatile
{
    using type = T;
};

template <typename T>
struct remove_volatile<volatile T>
{
    using type = T;
};

template <typename T>
struct remove_cv
{
    using type = typename remove_volatile<typename remove_const<T>::type>::type;
};

template <typename T>
using remove_cv_t = remove_cv<T>::type;

// Primary type categories
template <typename T>
struct is_void : is_same<void, remove_cv_t<T>>
{
};

template <typename T>
inline constexpr bool is_void_v = is_void<T>::value;

template <typename T>
struct is_null_pointer : is_same<std::nullptr_t, remove_cv_t<T>>
{
};

template <typename T>
inline constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

template <typename T>
    struct is_integral : bool_constant < requires(T ob, T *ptr, void (*f)(T *))
{
    ptr + ob;
    f(0);
    reinterpret_cast<T>(ob);
} >
    {};

template <typename T>
inline constexpr bool is_integral_v = is_integral<T>::value;

template <typename T>
struct is_floating_point
    : integral_constant<
          bool,
          is_same_v<float, T> ||
              is_same_v<double, T> ||
              is_same_v<long double, T>>
{
};

template <typename T>
inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

template <typename T>
struct is_array : false_type
{
};

template <typename T>
struct is_array<T[]> : true_type
{
};

template <typename T, std::size_t N>
struct is_array<T[N]> : true_type
{
};

template <typename T>
inline constexpr bool is_array_v = is_array<T>::value;

template <typename T>
struct is_enum : integral_constant<bool, __is_enum(T)>
{
};

template <typename T>
inline constexpr bool is_enum_v = is_enum<T>::value;

template <typename T>
struct is_class : integral_constant<bool, __is_class(T)>
{
};

template <typename T>
inline constexpr bool is_class_v = is_class<T>::value;

template <typename T>
struct is_union : integral_constant<bool, __is_union(T)>
{
};

template <typename T>
inline constexpr bool is_union_v = is_union<T>::value;

template <typename T>
struct is_pointer : false_type
{
};

template <typename T>
struct is_pointer<T *> : true_type
{
};

template <typename T>
struct is_pointer<T *const> : true_type
{
};

template <typename T>
struct is_pointer<T *volatile> : true_type
{
};

template <typename T>
struct is_pointer<T *const volatile> : true_type
{
};

template <typename T>
inline constexpr bool is_pointer_v = is_pointer<T>::value;

template <typename T>
struct is_lvalue_reference : false_type
{
};

template <typename T>
struct is_lvalue_reference<T &> : true_type
{
};

template <typename T>
inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

template <typename T>
struct is_rvalue_reference : false_type
{
};

template <typename T>
struct is_rvalue_reference<T &&> : true_type
{
};

template <typename T>
inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

template <typename T>
struct is_arithmetic : integral_constant<
                        bool,
                        is_integral_v<T> ||
                        is_floating_point_v<T>>
{
};

template <typename T>
inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

template <typename T>
struct is_fundamental : integral_constant<
                        bool,
                        is_arithmetic_v<T> ||
                        is_void_v<T> ||
                        is_null_pointer_v<T>>
{
};

template <typename T>
inline constexpr bool is_fundamental_v = is_fundamental<T>::value;

template <class T>
struct is_member_pointer_helper : false_type
{
};

template <class T, class U>
struct is_member_pointer_helper<T U::*> : true_type
{
};

template <class T>
struct is_member_pointer : is_member_pointer_helper<remove_cv_t<T>>
{
};

template <typename T>
inline constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

template <typename T>
struct is_member_function_pointer_helper : false_type
{
};

template <typename T, typename U>
struct is_member_function_pointer_helper<T (U::*)()> : true_type
{
};

template <typename T>
struct is_member_function_pointer
    : is_member_function_pointer_helper<remove_cv_t<T>>
{
};

template <typename T>
inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<T>::value;


template <typename T>
struct is_memeber_object_pointer : integral_constant<
                        bool,
                        is_member_function_pointer_v<T> ||
                        is_member_pointer_v<T> >
{};

template <typename T>
inline constexpr bool is_memeber_object_pointer_v = is_memeber_object_pointer<T>::value;

template <typename T>
struct is_scalar : integral_constant<
                        bool,
                        is_enum_v<T> ||
                        is_arithmetic_v<T> ||
                        is_pointer_v<T> ||
                        is_member_pointer_v<T> ||
                        is_null_pointer_v<T>
                        >
{
};
template <typename T>
inline constexpr bool is_scalar_v = is_scalar<T>::value;

template <typename T>
struct is_object : integral_constant<
                        bool,
                        is_scalar_v<T> ||
                        is_class_v<T> ||
                        is_array_v<T> ||
                        is_union_v<T>
                        >
{
};

template <typename T>
inline constexpr bool is_object_v = is_object<T>::value;

template <typename T>
struct is_compound : integral_constant<bool,
                    !is_fundamental_v<T>>
{
};

template <typename T>
inline constexpr bool is_compound_v = is_compound<T>::value;

template <typename T>
struct is_reference : false_type{};

template <typename T>
struct is_reference<T&> : true_type{};

template <typename T>
struct is_reference<T&&> : true_type{};

template <typename T>
inline constexpr bool is_reference_v = is_reference<T>::value;

template <typename T>
struct is_const : false_type{};

template <typename T>
struct is_const<const T> : true_type{};

template <typename T>
inline constexpr bool is_const_v = is_const<T>::value;

template <typename T>
struct is_volatile : false_type{};

template <typename T>
struct is_volatile<volatile T> : true_type{};


template <typename T>
inline constexpr bool is_volatile_v = is_volatile<T>::value;

template <bool val, typename T, typename U>
struct conditional
{
    using type = T;
};

template <typename T, typename U>
struct conditional<false, T, U>
{
    using type = U;
};

template <typename T>
struct add_const
{
    using type = const T;
};

template <typename T>
using add_const_t = add_const<T>::type;

template <typename T>
struct add_volatile
{
    using type = volatile T;
};

template <typename T>
using add_volatile_t = add_volatile<T>::type;

template <typename T>
struct add_cv
{
    using type = const volatile T;
};

template <typename T>
using add_cd_t = add_cv<T>::type;

template <typename T>
struct remove_reference{
    using type = T;
};

template <typename T>
struct remove_reference<T&>
{
    using type =T;
};

template <typename T>
struct remove_reference<T&&>
{
    using type =T;
};

template <typename T>
using remove_reference_t = remove_reference<T>::type;

template <typename T>
struct add_lvalue_reference {
    using type = T&;
};

template <>
struct add_lvalue_reference<void> {
    using type = void;
};

template <>
struct add_lvalue_reference<const void> {
    using type = const void;
};

template <>
struct add_lvalue_reference<volatile void> {
    using type = volatile void;
};

template <>
struct add_lvalue_reference<const volatile void> {
    using type = const volatile void;
};

template <typename T>
struct add_rvalue_reference {
    using type = T&&;
};

template <>
struct add_rvalue_reference<void> {
    using type = void;
};

template <>
struct add_rvalue_reference<const void> {
    using type = const void;
};

template <>
struct add_rvalue_reference<volatile void> {
    using type = volatile void;
};

template <>
struct add_rvalue_reference<const volatile void> {
    using type = const volatile void;
};

template <typename T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template <typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

template <typename T>
struct remove_pointer{
    using type = T;
};

template <typename T>
struct remove_pointer<T*>
{
    using type = T;
};

template <typename T>
struct remove_pointer<T* const>
{
    using type = T;
};

template <typename T>
struct remove_pointer<T* volatile>
{
    using type = T;
};

template <typename T>
struct remove_pointer<T* const volatile>
{
    using type = T;
};

template <typename T>
using remove_pointer_t = remove_pointer<T>::type;



// template <typename T>
#endif // TYPE_TRAITS_TPP
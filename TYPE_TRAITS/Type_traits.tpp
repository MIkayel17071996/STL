#ifndef TYPE_TRAITS_TPP
#define TYPE_TRAITS_TPP

namespace MTT
{

    // This struct represents a compile-time constant value of a given type.
    // It defines a type alias for the type T and a static constexpr variable 'value' that holds the constant value.
    template <typename T, T val>
    struct integral_constant
    {
        using type = T;                    // Alias for the type T.
        static constexpr type value = val; // Compile-time constant value of type T.

        // Conversion operator to allow the struct to be implicitly converted to its value.
        operator type() const
        {
            return value;
        }

        // Function call operator that returns the value.
        type operator()() const
        {
            return value;
        }
    };

    // Specialization of integral_constant for the boolean type.
    // This is useful for creating true/false type traits.
    template <bool val>
    struct bool_constant : integral_constant<bool, val>
    {
    };

    // Type aliases for true and false boolean constants.
    using true_type = bool_constant<true>;
    using false_type = bool_constant<false>;

    // Primary template for is_same, which checks if two types are the same.
    // By default, it inherits from false_type.
    template <typename T, typename U>
    struct is_same : false_type
    {
    };

    // Specialization of is_same for the case where both types are the same.
    // In this case, it inherits from true_type.
    template <typename T>
    struct is_same<T, T> : true_type
    {
    };

    // Helper variable template to easily access the value of is_same.
    template <typename T, typename U>
    inline constexpr bool is_same_v = is_same<T, U>::value;

    // Removes the const qualifier from a type.
    template <typename T>
    struct remove_const
    {
        using type = T;
    };

    // Specialization for const-qualified types. Removes the const qualifier.
    template <typename T>
    struct remove_const<const T>
    {
        using type = T;
    };

    // Removes the volatile qualifier from a type.
    template <typename T>
    struct remove_volatile
    {
        using type = T;
    };

    // Specialization for volatile-qualified types. Removes the volatile qualifier.
    template <typename T>
    struct remove_volatile<volatile T>
    {
        using type = T;
    };

    // Removes both const and volatile qualifiers from a type by using the remove_const and remove_volatile structs.
    template <typename T>
    struct remove_cv
    {
        using type = typename remove_volatile<typename remove_const<T>::type>::type;
    };

    // Helper alias template to easily access the type after removing const and volatile qualifiers.
    template <typename T>
    using remove_const_t = remove_const<T>::type; 

    template <typename T>
    using remove_volatile_t = remove_volatile<T>::type;

    template <typename T>
    using remove_cv_t = typename remove_cv<T>::type;

    // Checks if a type is void (after removing const/volatile qualifiers).
    template <typename T>
    struct is_void : is_same<void, remove_cv_t<T>>
    {
    };

    // Helper variable template to easily access the value of is_void.
    template <typename T>
    inline constexpr bool is_void_v = is_void<T>::value;

    // Checks if a type is a null pointer type (after removing const/volatile qualifiers).
    template <typename T>
    struct is_null_pointer : is_same<std::nullptr_t, remove_cv_t<T>>
    {
    };

    // Helper variable template to easily access the value of is_null_pointer.
    template <typename T>
    inline constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

    // Checks if a type is an integral type (e.g., int, char, etc.).
    // This requires a special syntax called "requires" in C++20, which is used for compile-time constraints.
    template <typename T>
        struct is_integral : bool_constant <
                             requires(T ob, T *ptr, void (*f)(T *))
    {
        ptr + ob;
        f(0);
        reinterpret_cast<T>(ob);
    } >
        {};

    // Helper variable template to easily access the value of is_integral.
    template <typename T>
    inline constexpr bool is_integral_v = is_integral<T>::value;

    // Checks if a type is a floating-point type (e.g., float, double, long double).
    template <typename T>
    struct is_floating_point : integral_constant<
                                   bool,
                                   is_same_v<float, T> ||
                                       is_same_v<double, T> ||
                                       is_same_v<long double, T>>
    {
    };

    // Helper variable template to easily access the value of is_floating_point.
    template <typename T>
    inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

    // Checks if a type is an array type (either an unbounded or bounded array).
    template <typename T>
    struct is_array : false_type
    {
    };

    // Specialization for unbounded array types (e.g., int[]).
    template <typename T>
    struct is_array<T[]> : true_type
    {
    };

    // Specialization for bounded array types (e.g., int[5]).
    template <typename T, std::size_t N>
    struct is_array<T[N]> : true_type
    {
    };

    // Helper variable template to easily access the value of is_array.
    template <typename T>
    inline constexpr bool is_array_v = is_array<T>::value;

    // Checks if a type is an enum type.
    template <typename T>
    struct is_enum : integral_constant<bool, __is_enum(T)>
    {
    };

    // Helper variable template to easily access the value of is_enum.
    template <typename T>
    inline constexpr bool is_enum_v = is_enum<T>::value;

    // Checks if a type is a class type.
    template <typename T>
    struct is_class : integral_constant<bool, __is_class(T)>
    {
    };

    // Helper variable template to easily access the value of is_class.
    template <typename T>
    inline constexpr bool is_class_v = is_class<T>::value;

    // Checks if a type is a union type.
    template <typename T>
    struct is_union : integral_constant<bool, __is_union(T)>
    {
    };

    // Helper variable template to easily access the value of is_union.
    template <typename T>
    inline constexpr bool is_union_v = is_union<T>::value;

    // Checks if a type is a pointer type (including pointers to cv-qualified types).
    template <typename T>
    struct is_pointer : false_type
    {
    };

    // Specialization for pointer types (e.g., int*).
    template <typename T>
    struct is_pointer<T *> : true_type
    {
    };

    // Specialization for const-qualified pointer types (e.g., int* const).
    template <typename T>
    struct is_pointer<T *const> : true_type
    {
    };

    // Specialization for volatile-qualified pointer types (e.g., int* volatile).
    template <typename T>
    struct is_pointer<T *volatile> : true_type
    {
    };

    // Specialization for const volatile-qualified pointer types (e.g., int* const volatile).
    template <typename T>
    struct is_pointer<T *const volatile> : true_type
    {
    };

    // Helper variable template to easily access the value of is_pointer.
    template <typename T>
    inline constexpr bool is_pointer_v = is_pointer<T>::value;

    // Checks if a type is an lvalue reference type (e.g., int&).
    template <typename T>
    struct is_lvalue_reference : false_type
    {
    };

    // Specialization for lvalue reference types.
    template <typename T>
    struct is_lvalue_reference<T &> : true_type
    {
    };

    // Helper variable template to easily access the value of is_lvalue_reference.
    template <typename T>
    inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

    // Checks if a type is an rvalue reference type (e.g., int&&).
    template <typename T>
    struct is_rvalue_reference : false_type
    {
    };

    // Specialization for rvalue reference types.
    template <typename T>
    struct is_rvalue_reference<T &&> : true_type
    {
    };

    // Helper variable template to easily access the value of is_rvalue_reference.
    template <typename T>
    inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

    // Checks if a type is an arithmetic type (either integral or floating-point).
    template <typename T>
    struct is_arithmetic : integral_constant<
                               bool,
                               is_integral_v<T> ||
                                   is_floating_point_v<T>>
    {
    };

    // Helper variable template to easily access the value of is_arithmetic.
    template <typename T>
    inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

    // Checks if a type is a fundamental type (either arithmetic, void, or null pointer).
    template <typename T>
    struct is_fundamental : integral_constant<
                                bool,
                                is_arithmetic_v<T> ||
                                    is_void_v<T> ||
                                    is_null_pointer_v<T>>
    {
    };

    // Helper variable template to easily access the value of is_fundamental.
    template <typename T>
    inline constexpr bool is_fundamental_v = is_fundamental<T>::value;

    // Helper struct to check if a type is a member pointer.
    template <class T>
    struct is_member_pointer_helper : false_type
    {
    };

    // Specialization for member pointers (e.g., int S::*).
    template <class T, class U>
    struct is_member_pointer_helper<T U::*> : true_type
    {
    };

    // Checks if a type is a member pointer (including cv-qualified types).
    template <class T>
    struct is_member_pointer : is_member_pointer_helper<remove_cv_t<T>>
    {
    };

    // Helper variable template to easily access the value of is_member_pointer.
    template <typename T>
    inline constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

    // Helper struct to check if a type is a member function pointer.
    template <typename T>
    struct is_member_function_pointer_helper : false_type
    {
    };

    // Specialization for member function pointers (e.g., void (S::*)()).
    template <typename T, typename U>
    struct is_member_function_pointer_helper<T (U::*)()> : true_type
    {
    };

    // Checks if a type is a member function pointer (including cv-qualified types).
    template <typename T>
    struct is_member_function_pointer : is_member_function_pointer_helper<remove_cv_t<T>>
    {
    };

    // Helper variable template to easily access the value of is_member_function_pointer.
    template <typename T>
    inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<T>::value;

    // Checks if a type is a member object pointer.
    template <typename T>
    struct is_member_object_pointer : integral_constant<
                                          bool,
                                          is_member_function_pointer_v<T> ||
                                              is_member_pointer_v<T>>
    {
    };

    // Helper variable template to easily access the value of is_member_object_pointer.
    template <typename T>
    inline constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value;

    // Checks if a type is a scalar type (enum, arithmetic, pointer, member pointer, or null pointer).
    template <typename T>
    struct is_scalar : integral_constant<
                           bool,
                           is_enum_v<T> ||
                               is_arithmetic_v<T> ||
                               is_pointer_v<T> ||
                               is_member_pointer_v<T> ||
                               is_null_pointer_v<T>>
    {
    };

    // Helper variable template to easily access the value of is_scalar.
    template <typename T>
    inline constexpr bool is_scalar_v = is_scalar<T>::value;

    // Checks if a type is an object type.
    // An object type can be a scalar, class, array, or union.
    template <typename T>
    struct is_object : integral_constant<
                           bool,
                           is_scalar_v<T> ||    // Scalars (e.g., int, float, pointers).
                               is_class_v<T> || // Classes (including structs and unions).
                               is_array_v<T> || // Arrays (both bounded and unbounded).
                               is_union_v<T>>   // Unions.
    {
    };

    // Helper variable template to easily access the value of is_object.
    template <typename T>
    inline constexpr bool is_object_v = is_object<T>::value;

    // Checks if a type is a compound type.
    // Compound types are those that are not fundamental (e.g., pointers, arrays, classes, etc.).
    template <typename T>
    struct is_compound : integral_constant<
                             bool,
                             !is_fundamental_v<T>> // A compound type is not a fundamental type.
    {
    };

    // Helper variable template to easily access the value of is_compound.
    template <typename T>
    inline constexpr bool is_compound_v = is_compound<T>::value;

    // Checks if a type is a reference type (either lvalue or rvalue).
    template <typename T>
    struct is_reference : false_type // Default case: not a reference type.
    {
    };

    // Specialization for lvalue reference types.
    template <typename T>
    struct is_reference<T &> : true_type // If T is an lvalue reference, then it's a reference type.
    {
    };

    // Specialization for rvalue reference types.
    template <typename T>
    struct is_reference<T &&> : true_type // If T is an rvalue reference, then it's a reference type.
    {
    };

    // Helper variable template to easily access the value of is_reference.
    template <typename T>
    inline constexpr bool is_reference_v = is_reference<T>::value;

    // Checks if a type is const-qualified.
    template <typename T>
    struct is_const : false_type // Default case: not const-qualified.
    {
    };

    // Specialization for const-qualified types.
    template <typename T>
    struct is_const<const T> : true_type // If T is const, then it is const-qualified.
    {
    };

    // Helper variable template to easily access the value of is_const.
    template <typename T>
    inline constexpr bool is_const_v = is_const<T>::value;

    // Checks if a type is volatile-qualified.
    template <typename T>
    struct is_volatile : false_type // Default case: not volatile-qualified.
    {
    };

    // Specialization for volatile-qualified types.
    template <typename T>
    struct is_volatile<volatile T> : true_type // If T is volatile, then it is volatile-qualified.
    {
    };

    // Helper variable template to easily access the value of is_volatile.
    template <typename T>
    inline constexpr bool is_volatile_v = is_volatile<T>::value;

    // Conditional type selector.
    // If 'val' is true, 'type' is T; otherwise, 'type' is U.
    template <bool val, typename T, typename U>
    struct conditional
    {
        using type = T; // If val is true, use T.
    };

    // Specialization for when 'val' is false.
    template <typename T, typename U>
    struct conditional<false, T, U>
    {
        using type = U; // If val is false, use U.
    };

    // Adds const-qualification to a type.
    template <typename T>
    struct add_const
    {
        using type = const T; // Makes T const.
    };

    // Helper alias template to easily access the const-qualified type.
    template <typename T>
    using add_const_t = add_const<T>::type;

    // Adds volatile-qualification to a type.
    template <typename T>
    struct add_volatile
    {
        using type = volatile T; // Makes T volatile.
    };

    // Helper alias template to easily access the volatile-qualified type.
    template <typename T>
    using add_volatile_t = add_volatile<T>::type;

    // Adds both const and volatile qualifications to a type.
    template <typename T>
    struct add_cv
    {
        using type = const volatile T; // Makes T const volatile.
    };

    // Helper alias template to easily access the const volatile-qualified type.
    template <typename T>
    using add_cv_t = add_cv<T>::type;

    // Removes reference (lvalue or rvalue) from a type.
    template <typename T>
    struct remove_reference
    {
        using type = T; // Default case: T has no reference to remove.
    };

    // Specialization for lvalue reference types.
    template <typename T>
    struct remove_reference<T &>
    {
        using type = T; // If T is an lvalue reference, remove the reference.
    };

    // Specialization for rvalue reference types.
    template <typename T>
    struct remove_reference<T &&>
    {
        using type = T; // If T is an rvalue reference, remove the reference.
    };

    // Helper alias template to easily access the type with references removed.
    template <typename T>
    using remove_reference_t = remove_reference<T>::type;

    // Adds lvalue reference to a type.
    template <typename T>
    struct add_lvalue_reference
    {
        using type = T &; // Adds lvalue reference to T.
    };

    // Specialization for void types to prevent invalid references.
    template <>
    struct add_lvalue_reference<void>
    {
        using type = void; // void cannot be referenced.
    };

    template <>
    struct add_lvalue_reference<const void>
    {
        using type = const void; // const void cannot be referenced.
    };

    template <>
    struct add_lvalue_reference<volatile void>
    {
        using type = volatile void; // volatile void cannot be referenced.
    };

    template <>
    struct add_lvalue_reference<const volatile void>
    {
        using type = const volatile void; // const volatile void cannot be referenced.
    };

    // Adds rvalue reference to a type.
    template <typename T>
    struct add_rvalue_reference
    {
        using type = T &&; // Adds rvalue reference to T.
    };

    // Specialization for void types to prevent invalid references.
    template <>
    struct add_rvalue_reference<void>
    {
        using type = void; // void cannot be referenced.
    };

    template <>
    struct add_rvalue_reference<const void>
    {
        using type = const void; // const void cannot be referenced.
    };

    template <>
    struct add_rvalue_reference<volatile void>
    {
        using type = volatile void; // volatile void cannot be referenced.
    };

    template <>
    struct add_rvalue_reference<const volatile void>
    {
        using type = const volatile void; // const volatile void cannot be referenced.
    };

    // Helper alias templates to easily access the lvalue and rvalue references.
    template <typename T>
    using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

    template <typename T>
    using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

    // Removes pointer from a type.
    template <typename T>
    struct remove_pointer
    {
        using type = T; // Default case: T has no pointer to remove.
    };

    // Specialization for pointer types.
    template <typename T>
    struct remove_pointer<T *>
    {
        using type = T; // If T is a pointer, remove the pointer.
    };

    // Specialization for const-qualified pointer types.
    template <typename T>
    struct remove_pointer<T *const>
    {
        using type = T; // If T is a const pointer, remove the pointer.
    };

    // Specialization for volatile-qualified pointer types.
    template <typename T>
    struct remove_pointer<T *volatile>
    {
        using type = T; // If T is a volatile pointer, remove the pointer.
    };

    // Specialization for const volatile-qualified pointer types.
    template <typename T>
    struct remove_pointer<T *const volatile>
    {
        using type = T; // If T is a const volatile pointer, remove the pointer.
    };

    // Helper alias template to easily access the type with pointers removed.
    template <typename T>
    using remove_pointer_t = remove_pointer<T>::type;

    // Conditionally enables a type if 'val' is true.
    // This is useful for SFINAE (Substitution Failure Is Not An Error) in templates.
    template <bool val, typename = void>
    struct enable_if
    {
        // Empty struct when 'val' is false.
    };

    // Specialization for when 'val' is true.
    template <typename T>
    struct enable_if<true, T>
    {
        using type = T; // If 'val' is true, enable the type T.
    };

};

#endif // TYPE_TRAITS_TPP
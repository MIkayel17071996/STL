#include <iostream>
// #include <type_traits> // For std::is_same, std::is_integral to compare

#include "Type_traits.cpp" // Ensure your header file is named correctly

// int main()
// {
//     std::cout << std::boolalpha;
//     // Test is_same
//     std::cout << "is_same<int, int>: " << is_same_v<int, int> << std::endl;
//     std::cout << "is_same<int, float>: " << is_same_v<int, float> << std::endl;

//     // Test remove_const and remove_cv
//     std::cout << "remove_const<const int>::type is int: " << is_same_v<remove_const<const int>::type, int> << std::endl;
//     std::cout << "remove_cv<const volatile int>::type is int: " << is_same_v<remove_cv_t<const volatile int>, int> << std::endl;

//     // Test is_void
//     std::cout << "is_void<void>: " << is_void_v<void> << std::endl;
//     std::cout << "is_void<int>: " << is_void_v<int> << std::endl;

//     // Test is_null_pointer
//     std::cout << "is_null_pointer<std::nullptr_t>: " << is_null_pointer_v<std::nullptr_t> << std::endl;
//     std::cout << "is_null_pointer<int*>: " << is_null_pointer_v<int*> << std::endl;

//     // Test is_integral
//     std::cout << "is_integral<int>: " << is_integral_v<int> << std::endl;
//     std::cout << "is_integral<float>: " << is_integral_v<float> << std::endl;

//     // Test is_floating_point
//     std::cout << "is_floating_point<double>: " << is_floating_point_v<double> << std::endl;
//     std::cout << "is_floating_point<int>: " << is_floating_point_v<int> << std::endl;

//     // Test is_array
//     std::cout << "is_array<int[]>: " << is_array_v<int[]> << std::endl;
//     std::cout << "is_array<int[5]>: " << is_array_v<int[5]> << std::endl;
//     std::cout << "is_array<int>: " << is_array_v<int> << std::endl;

//     // Test is_enum
//     enum E { A, B };
//     std::cout << "is_enum<E>: " << is_enum_v<E> << std::endl;
//     std::cout << "is_enum<int>: " << is_enum_v<int> << std::endl;

//     // Test is_class
//     struct S {};
//     std::cout << "is_class<S>: " << is_class_v<S> << std::endl;
//     std::cout << "is_class<int>: " << is_class_v<int> << std::endl;

//     // Test is_union
//     union U {};
//     std::cout << "is_union<U>: " << is_union_v<U> << std::endl;
//     std::cout << "is_union<int>: " << is_union_v<int> << std::endl;

//     // Test is_pointer
//     std::cout << "is_pointer<int*>: " << is_pointer_v<int*> << std::endl;
//     std::cout << "is_pointer<int>: " << is_pointer_v<int> << std::endl;

//     // Test is_lvalue_reference
//     std::cout << "is_lvalue_reference<int&>: " << is_lvalue_reference_v<int&> << std::endl;
//     std::cout << "is_lvalue_reference<int>: " << is_lvalue_reference_v<int> << std::endl;

//     // Test is_rvalue_reference
//     std::cout << "is_rvalue_reference<int&&>: " << is_rvalue_reference_v<int&&> << std::endl;
//     std::cout << "is_rvalue_reference<int>: " << is_rvalue_reference_v<int> << std::endl;

//     // Test is_arithmetic
//     std::cout << "is_arithmetic<int>: " << is_arithmetic_v<int> << std::endl;
//     std::cout << "is_arithmetic<double>: " << is_arithmetic_v<double> << std::endl;
//     std::cout << "is_arithmetic<void>: " << is_arithmetic_v<void> << std::endl;

//     // Test is_fundamental
//     std::cout << "is_fundamental<int>: " << is_fundamental_v<int> << std::endl;
//     std::cout << "is_fundamental<double>: " << is_fundamental_v<double> << std::endl;
//     std::cout << "is_fundamental<void>: " << is_fundamental_v<void> << std::endl;

//     // Test is_member_pointer
//     std::cout << "is_member_pointer<int S::*>: " << is_member_pointer_v<int S::*> << std::endl;
//     std::cout << "is_member_pointer<int*>: " << is_member_pointer_v<int*> << std::endl;

//     // Test is_member_function_pointer
//     std::cout << "is_member_function_pointer<void(S::*)()>: " << is_member_function_pointer_v<void(S::*)()> << std::endl;
//     std::cout << "is_member_function_pointer<int>: " << is_member_function_pointer_v<int> << std::endl;

//     // Test is_scalar
//     std::cout << "is_scalar<int>: " << is_scalar_v<int> << std::endl;
//     std::cout << "is_scalar<int*>: " << is_scalar_v<int*> << std::endl;
//     std::cout << "is_scalar<S>: " << is_scalar_v<S> << std::endl;

//     // Test is_object
//     std::cout << "is_object<int>: " << is_object_v<int> << std::endl;
//     std::cout << "is_object<S>: " << is_object_v<S> << std::endl;
//     std::cout << "is_object<int&>: " << is_object_v<int&> << std::endl;

//     // Test is_compound
//     std::cout << "is_compound<int*>: " << is_compound_v<int*> << std::endl;
//     std::cout << "is_compound<int>: " << is_compound_v<int> << std::endl;

//     // Test is_reference
//     std::cout << "is_reference<int&>: " << is_reference_v<int&> << std::endl;
//     std::cout << "is_reference<int>: " << is_reference_v<int> << std::endl;

//     // Test is_const
//     std::cout << "is_const<const int>: " << is_const_v<const int> << std::endl;
//     std::cout << "is_const<int>: " << is_const_v<int> << std::endl;

//     // Test is_volatile
//     std::cout << "is_volatile<volatile int>: " << is_volatile_v<volatile int> << std::endl;
//     // std::cout << "is_volatile<int>: " << is_volatile_v<int> << std::endl;

//     return 0;
// }

static_assert
(
    is_same_v<int, int> == true &&
    is_same_v<int, int*> == false &&
    is_same_v<int, int**> == false &&
    is_same_v<int, remove_pointer_t<int>> == true &&
    is_same_v<int, remove_pointer_t<int*>> == true &&
    is_same_v<int, remove_pointer_t<int**>> == false &&
    is_same_v<int, remove_pointer_t<int* const>> == true &&
    is_same_v<int, remove_pointer_t<int* volatile>> == true &&
    is_same_v<int, remove_pointer_t<int* const volatile>> == true
);
 
int main() {
    using non_ref = int;

    std::cout << "is_lvalue_reference_v<non_ref>: " << std::boolalpha << is_lvalue_reference_v<non_ref> << "\n";

    using l_ref = add_lvalue_reference_t<non_ref>;
    std::cout << "is_lvalue_reference_v<l_ref>: " << std::boolalpha << is_lvalue_reference_v<l_ref> << "\n";

    using r_ref = add_rvalue_reference_t<non_ref>;
    std::cout << "is_rvalue_reference_v<r_ref>: " << std::boolalpha << is_rvalue_reference_v<r_ref> << "\n";

    using void_ref = add_lvalue_reference_t<void>;
    std::cout << "is_reference_v<void_ref>: " << std::boolalpha << is_reference_v<void_ref> << "\n";

    return 0;
}
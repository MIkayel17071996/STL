#include <iostream>
#include <variant>
#include "Type_traits.tpp"

enum class Color
{
    Red,
    Green,
    Blue
};

class MyClass
{
};

union MyUnion
{
    int i;
    float f;
};

int main()
{
    using namespace MTT; // Using the MTT namespace
    
    std::cout << std::boolalpha;
    // Test integral_constant
    std::cout << "integral_constant<int, 42>::value: "
              << integral_constant<int, 42>::value
              << std::endl;
    ;
    std::cout << "integral_constant<int, 42>(): "
              << integral_constant<int, 42>()
              << std::endl;
    ;

    // Test bool_constant
    std::cout << "true_type::value: "
              << true_type::value
              << std::endl;
    std::cout << "false_type::value: "
              << false_type::value
              << std::endl;
    ;

    // Test is_same
    std::cout << "is_same<int, int>::value: "
              << is_same_v<int, int> << std::endl;
    std::cout << "is_same<int, float>::value: "
              << is_same_v<int, float> << std::endl;

    // Test remove_const
    std::cout << "remove_const<const int>::type: "
              << typeid(remove_const_t<const double>).name()
              << std::endl;
    std::cout << "remove_const<int>::type: "
              << typeid(remove_const_t<int>).name()
              << std::endl;

    // Test remove_volatile
    std::cout << "remove_volatile<volatile int>::type: "
              << typeid(remove_volatile_t<volatile int>).name()
              << std::endl;
    std::cout << "remove_volatile<int>::type: "
              << typeid(remove_volatile_t<int>).name()
              << std::endl;

    // Test remove_cv
    std::cout << "remove_cv<const volatile int>::type: "
              << typeid(remove_cv_t<const volatile int>).name()
              << std::endl;
    std::cout << "remove_cv<int>::type: "
              << typeid(remove_cv_t<int>).name()
              << std::endl;

    // Test is_void
    std::cout << "is_void<void>::value: "
              << is_void_v<void> << std::endl;
    std::cout << "is_void<int>::value: "
              << is_void_v<int> << std::endl;

    // Test is_null_pointer
    std::cout << "is_null_pointer<std::nullptr_t>::value: "
              << is_null_pointer_v<std::nullptr_t> << std::endl;
    std::cout << "is_null_pointer<int>::value: "
              << is_null_pointer_v<int> << std::endl;

    // Test is_integral
    std::cout << "is_integral<int>::value: "
              << is_integral_v<int> << std::endl;
    std::cout << "is_integral<float>::value: "
              << is_integral_v<float> << std::endl;

    // Test is_floating_point
    std::cout << "is_floating_point<float>::value: "
              << is_floating_point_v<float> << std::endl;
    std::cout << "is_floating_point<double>::value: "
              << is_floating_point_v<double> << std::endl;
    std::cout << "is_floating_point<int>::value: "
              << is_floating_point_v<int> << std::endl;

    // Test is_array
    std::cout << "is_array<int>::value: "
              << is_array_v<int> << std::endl;
    std::cout << "is_array<int[]>::value: "
              << is_array_v<int[]> << std::endl;
    std::cout << "is_array<int[5]>::value: "
              << is_array_v<int[5]> << std::endl;

    // Test is_enum
    std::cout << "is_enum<std::nullptr_t>::value: "
              << is_enum_v<std::nullptr_t> << std::endl;
    std::cout << "is_enum<Color>::value: "
              << is_enum_v<Color> << std::endl;

    // Test is_class
    std::cout << "is_class<int>::value: "
              << is_class_v<int> << std::endl;
    std::cout << "is_class<std::string>::value: "
              << is_class_v<std::string> << std::endl;

    // Test is_union
    std::cout << "is_union<int>::value: "
              << is_union_v<int> << std::endl;
    std::cout << "is_union<std::variant<int, float>>::value: "
              << is_union_v<std::variant<int, float>> << std::endl;

    // Test is_pointer
    std::cout << "is_pointer<int>::value: "
              << is_pointer_v<int> << std::endl;
    std::cout << "is_pointer<int*>::value: "
              << is_pointer_v<int *> << std::endl;
    std::cout << "is_pointer<int* const>::value: "
              << is_pointer_v<int *const> << std::endl;
    std::cout << "is_pointer<int* volatile>::value: "
              << is_pointer_v<int *volatile> << std::endl;
    std::cout << "is_pointer<int* const volatile>::value: "
              << is_pointer_v<int *const volatile> << std::endl;

    // Test is_lvalue_reference
    std::cout << "is_lvalue_reference<int>::value: "
              << is_lvalue_reference_v<int> << std::endl;
    std::cout << "is_lvalue_reference<int&>::value: "
              << is_lvalue_reference_v<int &> << std::endl;

    // Test is_rvalue_reference
    std::cout << "is_rvalue_reference<int>::value: "
              << is_rvalue_reference_v<int> << std::endl;
    std::cout << "is_rvalue_reference<int&&>::value: "
              << is_rvalue_reference_v<int &&> << std::endl;

    // Test is_arithmetic
    std::cout << "is_arithmetic<int>::value: "
              << is_arithmetic_v<int> << std::endl;
    std::cout << "is_arithmetic<float>::value: "
              << is_arithmetic_v<float> << std::endl;
    std::cout << "is_arithmetic<std::string>::value: "
              << is_arithmetic_v<std::string> << std::endl;

    // Test is_fundamental
    std::cout << "is_fundamental<int>::value: "
              << is_fundamental_v<int> << std::endl;
    std::cout << "is_fundamental<void>::value: "
              << is_fundamental_v<void> << std::endl;
    std::cout << "is_fundamental<std::nullptr_t>::value: "
              << is_fundamental_v<std::nullptr_t> << std::endl;
    std::cout << "is_fundamental<std::string>::value: "
              << is_fundamental_v<std::string> << std::endl;

    // Test is_member_pointer
    std::cout << "is_member_pointer<int>::value: "
              << is_member_pointer_v<int> << std::endl;
    std::cout << "is_member_pointer<int MyClass::*>::value: "
              << is_member_pointer_v<int MyClass::*> << std::endl;

    // Test is_member_function_pointer
    std::cout << "is_member_function_pointer<void(int)>::value: "
              << is_member_function_pointer_v<void(int)> << std::endl;
    std::cout << "is_member_function_pointer<void(MyClass::*)(int)>::value: "
              << is_member_function_pointer_v<void (MyClass::*)(int)> << std::endl;

    // Test is_member_object_pointer
    std::cout << "is_member_object_pointer<int>::value: "
              << is_member_object_pointer_v<int> << std::endl;
    std::cout << "is_member_object_pointer<int MyClass::*>::value: "
              << is_member_object_pointer_v<int MyClass::*> << std::endl;
    std::cout << "is_member_object_pointer<void(MyClass::*)(int)>::value: "
              << is_member_object_pointer_v<void (MyClass::*)(int)> << std::endl;

    std::cout << "is_object<int>::value: "
              << is_object_v<int> << std::endl;
    std::cout << "is_object<int[]>::value: "
              << is_object_v<int[]> << std::endl;
    std::cout << "is_object<MyClass>::value: "
              << is_object_v<MyClass> << std::endl;
    std::cout << "is_object<MyUnion>::value: "
              << is_object_v<MyUnion> << std::endl;

    // Test is_compound
    std::cout << "is_compound<int>::value: "
              << is_compound_v<int> << std::endl;
    std::cout << "is_compound<int[]>::value: "
              << is_compound_v<int[]> << std::endl;
    std::cout << "is_compound<MyClass>::value: "
              << is_compound_v<MyClass> << std::endl;

    // Test is_reference
    std::cout << "is_reference<int>::value: "
              << is_reference_v<int> << std::endl;
    std::cout << "is_reference<int&>::value: "
              << is_reference_v<int &> << std::endl;
    std::cout << "is_reference<int&&>::value: "
              << is_reference_v<int &&> << std::endl;

    // Test is_volatile
    std::cout << "is_volatile<int>::value: "
              << is_volatile_v<int> << std::endl;
    std::cout << "is_volatile<volatile int>::value: "
              << is_volatile_v<volatile int> << std::endl;

    // Test is_const
    std::cout << "is_const<int>::value: "
              << is_const_v<int> << std::endl;
    std::cout << "is_const<const int>::value: "
              << is_const_v<const int> << std::endl;
}

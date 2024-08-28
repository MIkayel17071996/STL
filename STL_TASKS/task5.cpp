#include <iostream>
//is_polymorphic
template <class T>
std::true_type detect_is_polymorphic(
decltype(dynamic_cast<const volatile void *>(static_cast<T *>(nullptr))));

template <class T>
std::false_type detect_is_polymorphic(...);

template <class T>
struct is_polymorphic : decltype(detect_is_polymorphic<T>(nullptr))
{
};

class A {};
class B { virtual void foo() {} };
class C : public B {};

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is A polymorphic? " << is_polymorphic<A>::value << std::endl;
    std::cout << "Is B polymorphic? " << is_polymorphic<B>::value << std::endl;
    std::cout << "Is C polymorphic? " << is_polymorphic<C>::value << std::endl;
}
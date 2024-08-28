#include <iostream>
#include <type_traits>

// TYpe_traits and SFINA example with concepts

class A{};
class B{};
class C{};

class D : public A{};
class E : public B, public C{};
class F : public A, public B, public C{};

template <typename T>
struct OwnTrait
{
    inline static constexpr bool value = (std::is_base_of<A, T>::value + std::is_base_of<B, T>::value + std::is_base_of<C, T>::value) == 1; 
};

template <typename T>
concept DerivedFromOne = OwnTrait<T>::value;

template <typename T>
concept DerivedFromMultiple = !OwnTrait<T>::value;

template <DerivedFromOne T>
void foo(const T& ob)
{
    std::cout << "T have exactly one base class" << std::endl;
}

template <DerivedFromMultiple T>
void foo(const T& ob)
{
    std::cout << "T have some base classes" << std::endl;
}

int main()
{
        D ob;
    E ob1;
    F ob2;

    foo(ob);
    foo(ob1);
    foo(ob2);
}
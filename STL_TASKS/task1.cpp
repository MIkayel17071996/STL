#include <iostream>


template <signed long long N>
struct ValueX
{
    static constexpr signed long long value = 2 * ValueX<N - 1>::value - 2 * ValueX<N - 2>::value - 3 * ValueX<N - 3>::value;
};

template <>
struct ValueX<0>
{
    static constexpr signed long long value = 0;
};

template <>
struct ValueX<1>
{
    static constexpr signed long long value = 1;
};

template <>
struct ValueX<2>
{
    static constexpr signed long long value = 2;
};



int main()
{
    std::cout << "X(17) = " << ValueX<17>::value << std::endl;
    std::cout << "X(50) = " << ValueX<50>::value << std::endl;


}

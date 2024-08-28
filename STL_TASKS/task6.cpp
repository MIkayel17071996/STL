#include <iostream>
// compile time checking is the number prime or composite
template <int N>
struct ValidValue {
    inline static constexpr bool value = (N > 0);
};

template <int N>
concept Valid = ValidValue<N>::value;


template <int N, int D>
struct divide {
    inline static constexpr bool value = (N % D == 0);
};

template <int N, int D = 2>
requires Valid<N>
struct is_prime {
    inline static constexpr bool value = (D * D > N) || (!divide<N, D>::value && is_prime<N, D + 1>::value);
};

template <>
struct is_prime<1> {
    inline static constexpr bool value = false;
};

template <>
struct is_prime<2> {
    inline static constexpr bool value = true;
};

template<int N>
struct is_prime<N, N> {
    inline static constexpr bool value = true;
};

template <int N>
requires Valid<N>
struct is_composite {
    inline static constexpr bool value = !is_prime<N>::value;
};

template <>
struct is_composite<1> {
    inline static constexpr bool value = false;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is 7 prime? " << is_prime<7>::value << std::endl;
    std::cout << "Is 10 prime? " << is_prime<10>::value << std::endl;
    std::cout << "Is 13 prime? " << is_prime<13>::value << std::endl;
    std::cout << "Is 2 prime? " << is_prime<2>::value << std::endl;
    std::cout << "Is 1 prime? " << is_prime<1>::value << std::endl;

    std::cout << std::endl;
    std::cout << "Is 7 composite? " << is_composite<7>::value << std::endl;
    std::cout << "Is 10 composite? " << is_composite<10>::value << std::endl;
    std::cout << "Is 13 composite? " << is_composite<13>::value << std::endl;
    std::cout << "Is 2 composite? " << is_composite<2>::value << std::endl;
    std::cout << "Is 1 composite? " << is_composite<1>::value << std::endl;

}

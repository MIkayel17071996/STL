#include <iostream>
#include <typeinfo>

template <size_t N, typename First, typename... Rest>
struct TypeAt {
    using Type = typename TypeAt<N - 1, Rest...>::Type;
};

template <typename First, typename... Rest>
struct TypeAt<0, First, Rest...> {
    using Type = First;
};

template <typename T>
void printType() {
    std::cout << typeid(T).name() << std::endl;
}

template <size_t N, auto... Values>
void printTypeAt() {
    using Type = typename TypeAt<N, decltype(Values)...>::Type;
    printType<Type>();
}

int main() {
    printTypeAt<1, 342, 11, 'a'>();  
}

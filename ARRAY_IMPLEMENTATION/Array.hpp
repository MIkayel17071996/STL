#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <initializer_list>
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"

// Templated class Array declaration
template <typename T, size_t SIZE>
class Array
{
public: // MEMEBER TYPES
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using iterator = RandomAccessIterator<T>;
    using const_iterator = const RandomAccessIterator<T>;
    using reverse_iterator = ReverseIterator<T>;
    using const_reverse_iterator = const ReverseIterator<T>;

public: // CONSTRUCTORS AND DESTRUCTOR
    Array() = default;
    ~Array() = default;
    Array(std::initializer_list<T>);
    Array(const Array &) = delete;
    Array &operator=(const Array &) = default;

public: // ELEMENT ACCESS
    reference at(size_type);             // O(1)
    const_reference at(size_type) const; // O(1)

    reference operator[](size_type pos);             // O(1)
    const_reference operator[](size_type pos) const; // O(1)

    reference front();             // O(1)
    const_reference front() const; // O(1)

    reference back();             // O(1)
    const_reference back() const; // O(1)

    pointer data() noexcept;             // O(1)
    const_pointer data() const noexcept; // O(1)

public: // ITERATORS
    iterator begin() noexcept;              // O(1)
    const_iterator cbegin() const noexcept; // O(1)

    iterator end() noexcept;              // O(1)
    const_iterator cend() const noexcept; // O(1)

    reverse_iterator rbegin() noexcept;              // O(1)
    const_reverse_iterator crbegin() const noexcept; // O(1)

    reverse_iterator rend() noexcept;              // O(1)
    const_reverse_iterator crend() const noexcept; // O(1)

public: // CAPASITY
    constexpr bool empty() const noexcept;         // O(1)
    constexpr size_type size() const noexcept;     // O(1)
    constexpr size_type max_size() const noexcept; // O(1)

public: // OPERATIONS
    void fill(const value_type &);        // O(n)
    void swap(Array &) noexcept; // O(n)

private: // DATA MEMBER
    value_type m_arr[SIZE];
};

#include "array.tpp"
#endif // ARRAY_H
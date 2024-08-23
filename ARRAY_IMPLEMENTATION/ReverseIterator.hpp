#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "RandomAccessIterator.hpp"

template <typename T>
class ReverseIterator
{
public: // MEMEBER TYPES
    using value_type = T;
    using reference = value_type&;
    using const_refernce = const reference;
    using pointer = value_type*;
    using const_pointer = const pointer;
public:
    // Constructor
    ReverseIterator(RandomAccessIterator<T>);

    // Dereference operator
    reference operator*() const;

    // Pointer access operator
    pointer operator->() const;

    // Pre-increment (move backwards)
    ReverseIterator &operator++();

    // Post-increment (move backwards)
    ReverseIterator operator++(int);

    // Pre-decrement (move forwards)
    ReverseIterator &operator--();

    // Post-decrement (move forwards)
    ReverseIterator operator--(int);

    // Comparison operators
    template <typename U>
    friend bool operator==(const ReverseIterator<U> &, const ReverseIterator<U> &);

    template <typename U>
    friend bool operator!=(const ReverseIterator<U> &, const ReverseIterator<U> &);

private:
    RandomAccessIterator<T> m_iter;
};

#include "ReverseIterator.tpp"

#endif // REVERSE_ITERATOR_HPP

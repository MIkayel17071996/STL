#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>

// Template class for a random access iterator
template <typename T>
class RandomAccessIterator
{
    // Type aliases for ease of use
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using difference_type = std::ptrdiff_t;

public:
    // Constructor that takes a pointer to the value_type
    RandomAccessIterator(pointer);

    // Constructor that takes a const pointer to the value_type
    RandomAccessIterator(const_pointer);

    // Copy constructor
    RandomAccessIterator(const RandomAccessIterator &);

public:
    // Dereference operator, returns a reference to the value pointed by m_ptr
    reference operator*() const;

    // Arrow operator, returns the pointer to the value
    pointer operator->() const;

    // Pre-increment operator, advances the iterator and returns the incremented iterator
    RandomAccessIterator &operator++();

    // Post-increment operator, advances the iterator and returns the original iterator
    RandomAccessIterator operator++(int);

    // Pre-decrement operator, moves the iterator backwards and returns the decremented iterator
    RandomAccessIterator &operator--();

    // Post-decrement operator, moves the iterator backwards and returns the original iterator
    RandomAccessIterator operator--(int);

    // Addition operator, returns a new iterator advanced by the specified number of elements
    RandomAccessIterator operator+(difference_type) const;

    // Subtraction operator, returns a new iterator moved backwards by the specified number of elements
    RandomAccessIterator operator-(difference_type) const;

    // Addition assignment operator, advances the iterator by the specified number of elements
    RandomAccessIterator &operator+=(difference_type);

    // Subtraction assignment operator, moves the iterator backwards by the specified number of elements
    RandomAccessIterator &operator-=(difference_type);

    // Difference operator, returns the distance between two iterators
    difference_type operator-(const RandomAccessIterator &) const;

    // Subscript operator, provides random access to elements at the specified index
    reference operator[](difference_type) const;

public:
    // Equality comparison operators
    template <typename U>
    friend bool operator==(const RandomAccessIterator<U> &, const RandomAccessIterator<U> &);

    template <typename U>
    friend bool operator!=(const RandomAccessIterator<U> &, const RandomAccessIterator<U> &);

    template <typename U>
    friend bool operator<(const RandomAccessIterator<U> &, const RandomAccessIterator<U> &);

    template <typename U>
    friend bool operator<=(const RandomAccessIterator<U> &, const RandomAccessIterator<U> &);

    template <typename U>
    friend bool operator>(const RandomAccessIterator<U> &, const RandomAccessIterator<U> &);

    template <typename U>
    friend bool operator>=(const RandomAccessIterator<U> &, const RandomAccessIterator<U> &);

private:
    // Pointer to the element the iterator currently points to
    pointer m_ptr;
};

#include "RandomAccessIterator.tpp" // Include the implementation file
#endif // RANDOMACCESSITERATOR_HPP

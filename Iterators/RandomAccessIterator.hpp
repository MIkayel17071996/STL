#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include <iterator>
template <typename T>
class RandomAccessIterator
{
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;

public:
    RandomAccessIterator(pointer);

    RandomAccessIterator(const_pointer);

    RandomAccessIterator(const RandomAccessIterator &);

public:
    reference operator*() const;

    pointer operator->() const;

    RandomAccessIterator &operator++();

    RandomAccessIterator operator++(int);

    RandomAccessIterator &operator--();

    RandomAccessIterator operator--(int);

    RandomAccessIterator operator+(difference_type) const;

    RandomAccessIterator operator-(difference_type) const;

    RandomAccessIterator &operator+=(difference_type);

    RandomAccessIterator &operator-=(difference_type);

    difference_type operator-(const RandomAccessIterator &) const;

    reference operator[](difference_type) const;

public:
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
    pointer m_ptr;
};

#include "RandomAccessIterator.tpp" 
#endif // RANDOMACCESSITERATOR_HPP

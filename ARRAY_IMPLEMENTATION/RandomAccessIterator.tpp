#ifndef RANDOM_ACCESS_ITERATOR_TPP
#define RANDOM_ACCESS_ITERATOR_TPP

#include "RandomAccessIterator.hpp"

// Constructor that initializes the iterator with a pointer to the value_type
template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(pointer ptr) 
    : m_ptr(ptr)
{
}

// Constructor that initializes the iterator with a const pointer to the value_type
template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(const_pointer ptr) 
    : m_ptr(const_cast<pointer>(ptr))
{
}

// Copy constructor that initializes the iterator with another iterator's pointer
template<typename T>
RandomAccessIterator<T>::RandomAccessIterator
(const RandomAccessIterator &other) 
    : m_ptr(other.m_ptr)
{
}

// Dereference operator, returns a reference to the value pointed by m_ptr
template<typename T>
typename RandomAccessIterator<T>::reference
RandomAccessIterator<T>::operator*() const
{
    return *m_ptr;
}

// Arrow operator, returns the pointer to the value
template<typename T>
typename RandomAccessIterator<T>::pointer
RandomAccessIterator<T>::operator->() const
{
    return m_ptr;
}

// Pre-increment operator, advances the iterator and returns the incremented iterator
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator& 
RandomAccessIterator<T>::operator++()
{
    ++m_ptr;
    return *this;
}

// Post-increment operator, advances the iterator and returns the original iterator
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator 
RandomAccessIterator<T>::operator++(int)
{
    RandomAccessIterator tmp = *this;
    ++(*this);
    return tmp;
}

// Pre-decrement operator, moves the iterator backwards and returns the decremented iterator
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator& 
RandomAccessIterator<T>::operator--()
{
    --m_ptr;
    return *this;
}

// Post-decrement operator, moves the iterator backwards and returns the original iterator
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator 
RandomAccessIterator<T>::operator--(int)
{
    RandomAccessIterator tmp = *this;
    --(*this);
    return tmp;
}

// Addition operator, returns a new iterator advanced by the specified number of elements
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator 
RandomAccessIterator<T>::operator+(difference_type n) const
{
    return RandomAccessIterator(m_ptr + n);
}

// Subtraction operator, returns a new iterator moved backwards by the specified number of elements
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator 
RandomAccessIterator<T>::operator-(difference_type n) const
{
    return RandomAccessIterator(m_ptr - n);
}

// Addition assignment operator, advances the iterator by the specified number of elements
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator&
RandomAccessIterator<T>::operator+=(difference_type n)
{
    m_ptr += n;
    return *this;
}

// Subtraction assignment operator, moves the iterator backwards by the specified number of elements
template<typename T>
typename RandomAccessIterator<T>::RandomAccessIterator&
RandomAccessIterator<T>::operator-=(difference_type n)
{
    m_ptr -= n;
    return *this;
}

// Difference operator, returns the distance between two iterators
template<typename T>
typename RandomAccessIterator<T>::difference_type
RandomAccessIterator<T>::operator-
(const RandomAccessIterator &other) const
{
    return m_ptr - other.m_ptr;
}

// Subscript operator, provides random access to elements at the specified index
template<typename T>
typename RandomAccessIterator<T>::reference
RandomAccessIterator<T>::operator[]
(difference_type n) const
{
    return *(m_ptr + n);
}

// Equality comparison operator for two iterators
template <typename U>
bool operator==(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr == rhs.m_ptr;
}

// Inequality comparison operator for two iterators
template <typename U>
bool operator!=(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr != rhs.m_ptr;
}

// Less than comparison operator for two iterators
template <typename U>
bool operator<(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr < rhs.m_ptr;
}

// Less than or equal comparison operator for two iterators
template <typename U>
bool operator<=(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr <= rhs.m_ptr;
}

// Greater than comparison operator for two iterators
template <typename U>
bool operator>(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr > rhs.m_ptr;
}

// Greater than or equal comparison operator for two iterators
template <typename U>
bool operator>=(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr >= rhs.m_ptr;
}

#endif // RANDOM_ACCESS_ITERATOR_TPP
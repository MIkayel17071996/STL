#ifndef REVERSE_ITERATOR_TPP
#define REVERSE_ITERATOR_TPP

#include "ReverseIterator.hpp"
#include "RandomAccessIterator.hpp"

// Constructor
template <typename T>
ReverseIterator<T>::ReverseIterator(RandomAccessIterator<T> iter)
    : m_iter(iter)
{
}

// Dereference operator
template <typename T>
typename ReverseIterator<T>::reference 
ReverseIterator<T>::operator*() const
{
    RandomAccessIterator<T> tmp = m_iter;
    --tmp;
    return *tmp;
}

// Pointer access operator
template <typename T>
typename ReverseIterator<T>::pointer
ReverseIterator<T>::operator->() const
{
    return &(operator*());
}

// Pre-increment (move backwards)
template <typename T>
ReverseIterator<T> &ReverseIterator<T>::operator++()
{
    --m_iter;
    return *this;
}

// Post-increment (move backwards)
template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int)
{
    ReverseIterator tmp = *this;
    --m_iter;
    return tmp;
}

// Pre-decrement (move forwards)
template <typename T>
ReverseIterator<T> &ReverseIterator<T>::operator--()
{
    ++m_iter;
    return *this;
}

// Post-decrement (move forwards)
template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator--(int)
{
    ReverseIterator tmp = *this;
    ++m_iter;
    return tmp;
}

// Comparison operators
template <typename U>
bool operator==(const ReverseIterator<U> &lhs, const ReverseIterator<U> &rhs)
{
    return lhs.m_iter == rhs.m_iter;
}

template <typename U>
bool operator!=(const ReverseIterator<U> &lhs, const ReverseIterator<U> &rhs)
{
    return lhs.m_iter != rhs.m_iter;
}

#endif // REVERSE_ITERATOR_TPP
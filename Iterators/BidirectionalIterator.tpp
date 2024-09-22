#ifndef BIDIRECTIONAL_ITERATOR_TPP
#define BIDIRECTIONAL_ITERATOR_TPP

#include <iostream>
#include "BidirectionalIterator.hpp"

template <typename T>
BidirectionalIt<T>::BidirectionalIt()  
    : m_ptr(nullptr)
{
}

template <typename T>
BidirectionalIt<T>::BidirectionalIt(typename BidirectionalIt<T>::pointer ptr)
    : m_ptr(ptr)
{
}

template <typename T>
BidirectionalIt<T>::BidirectionalIt(typename BidirectionalIt<T>::const_pointer ptr)
    : m_ptr(const_cast<pointer>(ptr))  
{
}

template <typename T>
BidirectionalIt<T>& BidirectionalIt<T>::operator=(const BidirectionalIt& other) 
{
    if (this != &other)  
    {
        m_ptr = other.m_ptr;
    }
    return *this;
}

template <typename T>
typename BidirectionalIt<T>::reference BidirectionalIt<T>::operator*()  
{
    return *m_ptr;
}

template <typename T>
typename BidirectionalIt<T>::const_reference BidirectionalIt<T>::operator*() const  
{
    return *m_ptr;
}

template <typename T>
typename BidirectionalIt<T>::pointer BidirectionalIt<T>::operator->()
{
    return m_ptr;
}

template <typename T>
typename BidirectionalIt<T>::const_pointer BidirectionalIt<T>::operator->() const
{
    return m_ptr;
}

template <typename T>
BidirectionalIt<T>& BidirectionalIt<T>::operator++()
{
    ++m_ptr;
    return *this;
}

template <typename T>
BidirectionalIt<T> BidirectionalIt<T>::operator++(int)
{
    BidirectionalIt tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename T>
BidirectionalIt<T>& BidirectionalIt<T>::operator--()
{
    --m_ptr;
    return *this;
}

template <typename T>
BidirectionalIt<T> BidirectionalIt<T>::operator--(int)
{
    BidirectionalIt tmp = *this;
    --m_ptr;
    return tmp;
}

template <typename U>
bool operator==(const BidirectionalIt<U>& lhs, const BidirectionalIt<U>& rhs)
{
    return lhs.m_ptr == rhs.m_ptr;
}

template <typename U>
bool operator!=(const BidirectionalIt<U>& lhs, const BidirectionalIt<U>& rhs)
{
    return lhs.m_ptr != rhs.m_ptr;
}

#endif // BIDIRECTIONAL_ITERATOR_TPP

#ifndef FORWARD_ITERATOR_TPP
#define FORWARD_ITERATOR_TPP

#include <iostream>
#include "ForwardIterator.hpp"

template <typename T>
ForwardIt<T>::ForwardIt()  
    : m_ptr(nullptr)
{
}

template <typename T>
ForwardIt<T>::ForwardIt(typename ForwardIt<T>::pointer ptr)
    : m_ptr(ptr)
{
}

template <typename T>
ForwardIt<T>::ForwardIt(typename ForwardIt<T>::const_pointer ptr)
    : m_ptr(const_cast<pointer>(ptr))  
{
}

template <typename T>
ForwardIt<T>& ForwardIt<T>::operator=(const ForwardIt& other) 
{
    if (this != &other)  
    {
        m_ptr = other.m_ptr;
    }
    return *this;
}

template <typename T>
typename ForwardIt<T>::reference ForwardIt<T>::operator*()  
{
    return *m_ptr;
}

template <typename T>
typename ForwardIt<T>::const_reference ForwardIt<T>::operator*() const  
{
    return *m_ptr;
}

template <typename T>
typename ForwardIt<T>::pointer ForwardIt<T>::operator->()
{
    return m_ptr;
}

template <typename T>
typename ForwardIt<T>::const_pointer ForwardIt<T>::operator->() const
{
    return m_ptr;
}

template <typename T>
ForwardIt<T>& ForwardIt<T>::operator++()
{
    ++m_ptr;
    return *this;
}

template <typename T>
ForwardIt<T> ForwardIt<T>::operator++(int)
{
    ForwardIt tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename U>
bool operator==(const ForwardIt<U>& lhs, const ForwardIt<U>& rhs)
{
    return lhs.m_ptr == rhs.m_ptr;
}

template <typename U>
bool operator!=(const ForwardIt<U>& lhs, const ForwardIt<U>& rhs)
{
    return lhs.m_ptr != rhs.m_ptr;
}

#endif // FORWARD_ITERATOR_TPP

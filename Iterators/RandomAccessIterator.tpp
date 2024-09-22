#ifndef RANDOM_ACCESS_ITERATOR_TPP
#define RANDOM_ACCESS_ITERATOR_TPP

#include "RandomAccessIterator.hpp"

template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(pointer ptr) 
    : m_ptr(ptr) 
{
}

template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(const_pointer ptr) 
    : m_ptr(const_cast<pointer>(ptr)) 
{
} 

template<typename T>
RandomAccessIterator<T>::RandomAccessIterator(const RandomAccessIterator &other) 
    : m_ptr(other.m_ptr) 
{
}

template<typename T>
typename RandomAccessIterator<T>::reference
RandomAccessIterator<T>::operator*() const {
    return *m_ptr;
}

template<typename T>
typename RandomAccessIterator<T>::pointer
RandomAccessIterator<T>::operator->() const {
    return m_ptr;
}

template<typename T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator++() {
    ++m_ptr;
    return *this;
}

template<typename T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator++(int) {
    RandomAccessIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator--() {
    --m_ptr;
    return *this;
}

template<typename T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator--(int) {
    RandomAccessIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator+(difference_type n) const 
{
    return RandomAccessIterator(m_ptr + n);
}

template<typename T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator-(difference_type n) const 
{
    return RandomAccessIterator(m_ptr - n);
}

template<typename T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator+=(difference_type n) 
{
    m_ptr += n;
    return *this;
}

template<typename T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator-=(difference_type n) 
{
    m_ptr -= n;
    return *this;
}

template<typename T>
typename RandomAccessIterator<T>::difference_type
RandomAccessIterator<T>::operator-(const RandomAccessIterator &other) const 
{
    return m_ptr - other.m_ptr;
}

template<typename T>
typename RandomAccessIterator<T>::reference
RandomAccessIterator<T>::operator[](difference_type n) const 
{
    return *(m_ptr + n);
}

template <typename U>
bool operator==(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr == rhs.m_ptr;
}

template <typename U>
bool operator!=(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr != rhs.m_ptr;
}

template <typename U>
bool operator<(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr < rhs.m_ptr;
}

template <typename U>
bool operator<=(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr <= rhs.m_ptr;
}

template <typename U>
bool operator>(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs) 
{
    return lhs.m_ptr > rhs.m_ptr;
}

template <typename U>
bool operator>=(const RandomAccessIterator<U>& lhs, const RandomAccessIterator<U>& rhs)
{
    return lhs.m_ptr >= rhs.m_ptr;
}

#endif // RANDOM_ACCESS_ITERATOR_TPP

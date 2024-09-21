#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include "stdexcept"
#include <initializer_list>
#include <iostream>
#include "Array.hpp"
#include <algorithm>

// Constructor with initializer_list
template <typename T, size_t SIZE>
Array<T, SIZE>::Array(std::initializer_list<T> list)
{
    if (list.size() > SIZE)
    {
        throw std::out_of_range("Initializer list size exceeds array size");
    }
    std::copy(list.begin(), list.end(), m_arr);
}

// Method at, returning an element of given position
template <typename T, size_t SIZE>
typename Array<T, SIZE>::reference 
Array<T, SIZE>::at(size_type pos)
{
    if (pos >= SIZE)
    {
        throw std::out_of_range("Array index out of range");
    }
    return m_arr[pos];
}

// Const Method at, returning an element of given position
// if position out of range , throwing exception std::out_of_range
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_reference 
Array<T, SIZE>::at(size_type pos) const
{
    if (pos >= SIZE)
    {
        throw std::out_of_range("Array index out of range");
    }
    return m_arr[pos];
}

// Operator [], returning an element of given position
// Do not throwing exception
template <typename T, size_t SIZE>
typename Array<T, SIZE>::reference 
Array<T, SIZE>::operator[](size_type pos)
{
    return m_arr[pos];
}

//Const Operator [], returning an element of given position
// Do not throwing exception
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_reference 
Array<T, SIZE>::operator[](size_type pos) const
{
    return m_arr[pos];
}

// Method front, Returns a reference to the first element in the container.
// Calling front on an empty container causes undefined behavior.
template <typename T, size_t SIZE>
typename Array<T, SIZE>::reference 
Array<T, SIZE>::front()
{
    return m_arr[0];
}

// Const Method front
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_reference 
Array<T, SIZE>::front() const
{
    return m_arr[0];
}

// Method back, Returns a reference to the last element in the container.
// Calling back on an empty container causes undefined behavior.
template <typename T, size_t SIZE>
typename Array<T, SIZE>::reference 
Array<T, SIZE>::back()
{
    return m_arr[SIZE - 1];
}

// Const Method back
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_reference 
Array<T, SIZE>::back() const
{
    return m_arr[SIZE -1];
}

// Method data
//Direct access to the underlying contiguous storage
template <typename T, size_t SIZE>
typename Array<T, SIZE>::pointer
Array<T, SIZE>::data() noexcept
{
    return m_arr;
}

// Const Method data
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_pointer
Array<T, SIZE>::data() const noexcept
{
    return m_arr;
}

// Returning iterator to first element in the container
template <typename T, size_t SIZE>
typename Array<T, SIZE>::iterator
Array<T, SIZE>::begin()  noexcept
{
    return iterator(&m_arr[0]);
}

// Returning const_iterator to first element in the container
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_iterator
Array<T, SIZE>::cbegin() const noexcept
{
    return const_iterator(&m_arr[0]);
}

// Returning iterator to last element in the container
template <typename T, size_t SIZE>
typename Array<T, SIZE>::iterator
Array<T, SIZE>::end()  noexcept
{
    return iterator(&m_arr[SIZE]);
}

// Returning const_iterator to last element in the container
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_iterator
Array<T, SIZE>::cend() const noexcept
{
    return const_iterator(&m_arr[SIZE]);
}

// Returning reverse_iterator to last element in the container
template <typename T, size_t SIZE>
typename Array<T, SIZE>::reverse_iterator
Array<T, SIZE>::rbegin()  noexcept
{
    return reverse_iterator(&m_arr[SIZE]);
}

// Returning const_reverse_iterator to last element in the container
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_reverse_iterator
Array<T, SIZE>::crbegin() const noexcept
{
    return const_reverse_iterator(&m_arr[SIZE]);
}

//returns a reverse iterator to the end
template <typename T, size_t SIZE>
typename Array<T, SIZE>::reverse_iterator
Array<T, SIZE>::rend()  noexcept
{
    return reverse_iterator(m_arr);
}

//returns a const reverse iterator to the end
template <typename T, size_t SIZE>
typename Array<T, SIZE>::const_reverse_iterator
Array<T, SIZE>::crend() const noexcept
{
    return const_reverse_iterator(m_arr);
}

// Return true if array is empty, otherwise false
template <typename T, size_t SIZE>
constexpr bool Array<T, SIZE>::empty() const noexcept
{
    return !SIZE;
}

// Returns the size of the array
template <typename T, size_t SIZE>
constexpr typename Array<T, SIZE>::size_type 
Array<T, SIZE>::size() const noexcept
{
    return SIZE;
}

// Acctually returns the size
template <typename T, size_t SIZE>
constexpr typename Array<T, SIZE>::size_type 
Array<T, SIZE>::max_size() const noexcept
{
    return SIZE;
}

// Fill the whole array with given value
template <typename T, size_t SIZE>
void Array<T, SIZE>::fill
(typename Array<T, SIZE>::const_reference value) 
{
    for (auto &it : m_arr)
    {
        it = value;
    }
}

// Swaping the contents of two arrays
template <typename T, size_t SIZE>
void Array<T, SIZE>::swap(Array& other) noexcept
{
    using std::swap;

    std::swap(this->m_arr, other.m_arr);

}

#endif // ARRAY_TPP

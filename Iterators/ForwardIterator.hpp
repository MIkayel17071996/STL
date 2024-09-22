#ifndef FORWARD_ITERATOR_HPP
#define FORWARD_ITERATOR_HPP

#include <iterator>

template <class T>
class ForwardIt
{
public:
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

public:
    ForwardIt();
    explicit ForwardIt(pointer);
    explicit ForwardIt(const_pointer);
    ForwardIt& operator=(const ForwardIt&);

    reference operator*();
    const_reference operator*() const;

    pointer operator->();
    const_pointer operator->() const;

    ForwardIt& operator++();
    ForwardIt operator++(int);

    template <typename U>
    friend bool operator==(const ForwardIt<U>&, const ForwardIt<U>&);

    template <typename U>
    friend bool operator!=(const ForwardIt<U>&, const ForwardIt<U>&);

private:
    pointer m_ptr;
};

#include "ForwardIterator.tpp"

#endif // FORWARD_ITERATOR_HPP

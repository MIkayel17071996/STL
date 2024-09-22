#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <iterator>

template <class T>
class BidirectionalIt
{
public:
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

public:
    BidirectionalIt();
    explicit BidirectionalIt(pointer);
    explicit BidirectionalIt(const_pointer);
    BidirectionalIt& operator=(const BidirectionalIt&);

    reference operator*();
    const_reference operator*() const;

    pointer operator->();
    const_pointer operator->() const;

    BidirectionalIt& operator++();
    BidirectionalIt operator++(int);

    BidirectionalIt& operator--();
    BidirectionalIt operator--(int);

    template <typename U>
    friend bool operator==(const BidirectionalIt<U>&, const BidirectionalIt<U>&);

    template <typename U>
    friend bool operator!=(const BidirectionalIt<U>&, const BidirectionalIt<U>&);

private:
    pointer m_ptr;
};

#include "BidirectionalIterator.tpp"

#endif // BIDIRECTIONAL_ITERATOR_HPP

#ifndef INPUT_ITERATOR_HPP
#define INPUT_ITERATOR_HPP

#include <iterator>

template <typename T>
class InputIt {
public:
    using value_type = T; 
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using iterator_category = std::input_iterator_tag; 
    using difference_type = std::ptrdiff_t; 

    explicit InputIt(pointer);
    explicit InputIt(const_pointer);
    
    InputIt(const InputIt&);
    
    const_reference operator*() const;
    const_pointer operator->() const;
    
    InputIt& operator++();
    InputIt operator++(int);
    
    template <typename U>
    friend bool operator==(const InputIt<U>&, const InputIt<U>&);
    
    template <typename U>
    friend bool operator!=(const InputIt<U>&, const InputIt<U>&);

private:
    const_pointer m_ptr;
};

#include "InputIterator.tpp"
#endif // INPUT_ITERATOR_HPP

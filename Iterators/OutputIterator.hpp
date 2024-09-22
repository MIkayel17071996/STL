#ifndef OUTPUT_ITERATOR_HPP
#define OUTPUT_ITERATOR_HPP

#include <iterator>

template <typename T>
class OutputIt {
public:
    using value_type = T; 
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::output_iterator_tag; 

    explicit OutputIt(pointer);
    OutputIt(const OutputIt&);

    OutputIt& operator=(const value_type&); 
    OutputIt& operator*(); 
    OutputIt& operator++();
    OutputIt operator++(int); 

private:
    pointer m_ptr;
};

#include "OutputIterator.tpp"

#endif // OUTPUT_ITERATOR_HPP

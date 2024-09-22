#ifndef OUTPUT_ITERATOR_TPP
#define OUTPUT_ITERATOR_TPP

template <typename T>
OutputIt<T>::OutputIt(pointer ptr) 
    : m_ptr(ptr) 
{
}

template <typename T>
OutputIt<T>& OutputIt<T>::operator=(const value_type& value) { 
    *m_ptr = value; 
    return *this; 
}

template <typename T>
OutputIt<T>::OutputIt(const OutputIt& other)
     : m_ptr(other.m_ptr) 
{
}


template <typename T>
OutputIt<T>& OutputIt<T>::operator*() {
    return *this;
}

template <typename T>
OutputIt<T>& OutputIt<T>::operator++() {
    ++m_ptr;
    return *this;
}

template <typename T>
OutputIt<T> OutputIt<T>::operator++(int) {
    OutputIt tmp = *this;
    ++m_ptr; 
    return tmp;
}

#endif // OUTPUT_ITERATOR_TPP
#ifndef INPUT_ITERATOR_TPP
#define INPUT_ITERATOR_TPP

template <typename T>
InputIt<T>::InputIt(pointer ptr) 
    : m_ptr(ptr) 
{
}

template <typename T>
InputIt<T>::InputIt(const_pointer ptr) 
    : m_ptr(ptr) 
{
}

template <typename T>
InputIt<T>::InputIt(const InputIt& other) 
    : m_ptr(other.m_ptr) 
{
}


template <typename T>
typename InputIt<T>::const_reference InputIt<T>::operator*() const {
    return *m_ptr;
}

template <typename T>
typename InputIt<T>::const_pointer InputIt<T>::operator->() const 
{
    return m_ptr;
}

template <typename T>
InputIt<T>& InputIt<T>::operator++() {
    ++m_ptr;
    return *this;
}

template <typename T>
InputIt<T> InputIt<T>::operator++(int) {
    InputIt tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename U>
bool operator==(const InputIt<U>& lhs, const InputIt<U>& rhs)
{
    return lhs.m_ptr == rhs.m_ptr;
}

template <typename U>
bool operator!=(const InputIt<U>& lhs, const InputIt<U>& rhs)
{
    return lhs.m_ptr != rhs.m_ptr;
}

#endif // INPUT_ITERATOR_TPP
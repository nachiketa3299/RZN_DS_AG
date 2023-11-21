/// @file Iterator.hpp
/// @author RZN

#ifndef _ITERATOR_HPP
#define _ITERATOR_HPP

#include "DSAG_Types.h"

/// @class IIterator
/// @short Iterator 들의 공통 조상
/*! @details 다음을 만족해야함\n
- 1. Copy-Constructible\n
- 2. Destructible\n
- 3. Copy-Assignable\n
*/
template <typename T>
class RIterator abstract
{
public:
    using Container_T = T;
public:
    RIterator(const RIterator& obj) {}
    virtual ~RIterator() {}
    RIterator& operator=(const RIterator& obj) {}
public:
    Container_T& operator++(RIterator);
    Container_T& operator++();
private:
    Container_T* ptr;
};

template <typename T>
class RForwardIterator: public RIterator<T>
{
    using Container_T = RIterator<T>::Container_T;
public:
    RForwardIterator() {};
public:
    bool operator==(const RIOIterator&) const;
    bool operator!=(const RIOIterator&) const;
    Container_T&& operator*() const;
    Container_T&& operator->();

    Container_T& operator*();
};

template <typename T>
class RBidirectionalIterator: public RForwardIterator<T>
{
    using Container_T = RForwardIterator<T>::Container_T;
public:
    Container_T& operator--(RBidirectionalIterator);
    Container_T& operator--();
};

template <typename T>
class RRandomAccessIterator: public RBidirectionalIterator<T>
{
    using Container_T = RBidirectionalIterator<T>::Container_T;
public:
    friend RRandomAccessIterator& operator+(RRandomAccessIterator&, const RRandomAccessIterator&);
    friend RRandomAccessIterator& operator+(const RRandomAccessIterator&, RRandomAccessIterator&);
    RRandomAccessIterator& operator+=(const RRandomAccessIterator&);
    RRandomAccessIterator& operator-=(const RRandomAccessIterator&);
public:
    RRandomAccessIterator* operator[](SizeType) const;
};

#endif // !_ITERATOR_HPP

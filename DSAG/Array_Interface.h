/// @file Array.h
/// @author RZN

#ifndef _ARRAY_INTERFACE_H
#define _ARRAY_INTERFACE_H

#include "DSAGTypes.h"

template<typename DataType>
class IArray abstract
{
public:
    virtual DataType& at(IndexType i) abstract;
    virtual DataType& operator[](IndexType i) abstract;
    virtual const DataType& get(IndexType i) const abstract;
    virtual SizeType size() const abstract;
};

#endif // _ARRAY_INTERFACE_H
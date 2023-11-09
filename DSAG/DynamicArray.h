/// @file DynamicArray.h
/// @author RZN

#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H

#include "Array.h"
#include "DSAGTypes.h"

/// @class RDyanmicArray
/// @short 동적 배열 클래스
template <typename DataType>
class RDynamicArray:
    public RArray<DataType>
{
public:
    RDynamicArray();
    /// @short 초기값이 있는 동적 배열 생성자
    /// @param[in] init_val 배열의 전체 요소를 이 값으로 초기화한다.
    RDynamicArray(SizeType size, const DataType& init_val=0);
    ~RDynamicArray() { delete[] this->dptr; }

    SizeType size() const override { return this->_size; };
private:
    static const SizeType overflow_multiplier = 2;
    static const SizeType init_size = 5;
    SizeType _size;
};

template <typename DataType>
RDynamicArray<DataType>::RDynamicArray():
    _size(RDynamicArray::init_size)
{
    this->dptr = new DataType[_size * RDynamicArray::overflow_multiplier];
}

template <typename DataType>
RDynamicArray<DataType>::RDynamicArray(SizeType size, const DataType& init_val):
    _size(size)
{
    this->dptr = new DataType[size * RDynamicArray::overflow_multiplier];
    for (SizeType i = 0; i < _size; ++i)
        this->dptr[i] = init_val;
}

#endif // _DYNAMIC_ARRAY_H
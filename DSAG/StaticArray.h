/// @file StaticArray.h
/// @author RZN

#ifndef _STATIC_ARRAY_H
#define _STATIC_ARRAY_H

#include "Array.h"

/// @class RStaticArray
/// @short 정적 배열 클래스
template <typename DataType, SizeType Size>
class RStaticArray: public RArray<DataType>
{
public:
    RStaticArray();
    /// @short 초기값이 있는 정적 배열 생성자.
    /// @param[in] init_val 배열의 전체 요소를 이 값으로 초기화한다. 
    RStaticArray(const DataType& init_val);
    ~RStaticArray() {};

    /// @short 정적 배열의 크기를 반환한다.
    /// @return 정적 배열의 크기
    SizeType size() const override { return Size; };
private:
    DataType data[Size];
};

template <typename DataType, SizeType Size>
RStaticArray<DataType, Size>::RStaticArray()
{
    this->dptr = &data[0];
}

template <typename DataType, SizeType Size>
RStaticArray<DataType, Size>::RStaticArray(const DataType& init_val)
{
    this->dptr = &data[0];
    for (IndexType i = 0; i < Size; ++i)
        this->dptr[i] = init_val;
}

#endif
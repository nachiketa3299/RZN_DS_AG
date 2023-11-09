/// @file StaticArray.h
/// @author RZN

#ifndef _STATIC_ARRAY_H
#define _STATIC_ARRAY_H

#include "Array.h"

/// @class RStaticArray
/// @short ���� �迭 Ŭ����
template <typename DataType, SizeType Size>
class RStaticArray: public RArray<DataType>
{
public:
    RStaticArray();
    /// @short �ʱⰪ�� �ִ� ���� �迭 ������.
    /// @param[in] init_val �迭�� ��ü ��Ҹ� �� ������ �ʱ�ȭ�Ѵ�. 
    RStaticArray(const DataType& init_val);
    ~RStaticArray() {};

    /// @short ���� �迭�� ũ�⸦ ��ȯ�Ѵ�.
    /// @return ���� �迭�� ũ��
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
/// @file StaticArray.h
/// @author RZN

#ifndef _STATIC_ARRAY_H
#define _STATIC_ARRAY_H

#include "DSAGTypes.h"

/// @class RStaticArray
/// @short ���� �迭 Ŭ����
template <typename DataType, SizeType Size>
class RStaticArray
{
public:
    RStaticArray() {};
    /// @short �ʱⰪ�� �ִ� ���� �迭 ������.
    /// @param[in] init_val �迭�� ��ü ��Ҹ� �� ������ �ʱ�ȭ�Ѵ�. 
    RStaticArray(const DataType& init_val);

    /// @todo ��ȿ���� ���� �ε����� ���� ���� ��û�� ������ ��� ó���ϱ�
    /// @short ���� �迭 ���� ����
    /// @param[in] i ������ ���� �迭 ����� �ε���
    /// @return �ε����� �ش��ϴ� ���� �迭 ���
    DataType& at(IndexType i);

    /// @short ���� �迭 ���� ����
    /// @param[in] i ������ ���� �迭 ����� �ε���
    /// @return �ε����� �ش��ϴ� ���� �迭 ���
    DataType& operator[](IndexType i);

    /// @short ���� �迭 ���� ����. ���ٸ� �����ϴ�.
    /// @param[in] i ������ ���� �迭 ����� �ε���
    /// @return �ε����� �ش��ϴ� ���� �迭 ���
    const DataType& get(IndexType i) const;

    /// @short ���� �迭�� ũ�⸦ ��ȯ�Ѵ�.
    /// @return ���� �迭�� ũ��
    SizeType size() const { return Size; };
private:
    /// @short ���ڷ� ���޵� �ε����� ���� �迭 ���ٿ� ��ȿ���� �˻��Ѵ�.
    /// @param[in] i �˻��� �ε���
    /// @return ���ڷ� ���޵� �ε����� ���� �迭 ���� ��ȿ�� ����
    bool is_valid_index(IndexType i) const { return (i < Size ? true : false); };
private:
    DataType data[Size];
};

template <typename DataType, SizeType Size>
RStaticArray<DataType, Size>::RStaticArray(const DataType& init_val)
{
    for (IndexType i = 0; i < Size; ++i)
        data[i] = init_val;
}

template <typename DataType, SizeType Size>
DataType& RStaticArray<DataType, Size>::at(IndexType i)
{
    return *(data + i);
}

template <typename DataType, SizeType Size>
DataType& RStaticArray<DataType, Size>::operator[](IndexType i)
{
    return *(data + i);
}

template <typename DataType, SizeType Size>
const DataType& RStaticArray<DataType, Size>::get(IndexType i) const
{
    return *(data + i);
}

#endif
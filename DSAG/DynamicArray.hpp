/// @file DynamicArray.hpp
/// @author RZN

#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP

#include "Array.hpp"

namespace RArray
{
/// @class RDyanmicArray
/// @short ���� �迭 Ŭ����
template <typename DataType>
class Dynamic: 
    public RArray<DataType>
{
    using RLinear<DataType>::_size;
    using RLinear<DataType>::_capacity;
    using RLinear<DataType>::_dptr;

public:  /* CONSTRUCTORS */
    /// @short �ƹ� ���ڰ� ���� ���� �迭 ������. �ʱ� ĳ�۽�Ƽ�� ������ �������� �Ҵ���.
    Dynamic();

    /// @short �ʱ� ũ�⸸ �޴� ���� �迭 ������.
    /// @param[in] size ������ ���� �迭�� ũ��
    Dynamic(SizeType init_size);

    /// @short �ʱⰪ�� �ִ� ���� �迭 ������
    /// @param[in] size ������ ���� �迭�� ũ��
    /// @param[in] init_val ������ ���� �迭�� �� ���Ұ� �ʱ�ȭ�� ��
    Dynamic(SizeType init_size, const DataType& init_val);

    virtual ~Dynamic() { delete[] this->_dptr; };

    SizeType capacity() const { return this->_capacity; };

    void resize(SizeType new_size);
    void resize(SizeType new_size, const DataType& init_val);
    void reserve(SizeType new_capacity);
    void assign(const DataType& new_val, SizeType new_size) override;
    void push_back(const DataType& push_val);
};
} // RArray


template <typename DataType>
RArray::Dynamic<DataType>::Dynamic():
    RArray<DataType>(ZERO_SIZE, INIT_CAPACITY)
{
    /// ���� �Ҵ�
    this->_dptr = new DataType[_capacity];
}

template<typename DataType>
RArray::Dynamic<DataType>::Dynamic(SizeType init_size)
{
    this->_size = init_size;
    if (this->_capacity < this->_size)
        this->_capacity = this->_size * OVERFLOW_MULTIPLIER;

    /// ���� �Ҵ�
    this->_dptr = new DataType[_capacity];
}

template <typename DataType>
RArray::Dynamic<DataType>::Dynamic(SizeType init_size, const DataType& init_val)
{
    this->_size = init_size;
    if (this->_capacity < this->_size)
        this->_capacity = this->_size * OVERFLOW_MULTIPLIER;

    /// ���� �Ҵ�
    this->_dptr = new DataType[_capacity];

    /// �ʱ� �� �Ҵ�
    for (SizeType i = 0; i < _size; ++i)
        this->_dptr[i] = init_val;
    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::resize(SizeType new_size)
{
    /// ���ο� ����� ���� ������� ������ �� �� �ʿ䰡 ����
    if (new_size == this->_size)
        return;
    /// ���ο� ����� ���� ������� ū ���
    else if (new_size > this->_size)
    {
        if (new_size > this->_capacity)
            this->reserve(new_size * OVERFLOW_MULTIPLIER);
        this->_size = new_size;
    }
    /// ���ο� ����� ���� ������� ���� ���
    else if (new_size < this->_size)
    {
        this->_size = new_size;
    }

    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::resize(SizeType new_size, const DataType& init_val)
{
    /// ���ο� ����� ���� ������� ������ �� �� �ʿ䰡 ����
    if (new_size == this->_size)
        return;
    /// ���ο� ����� ���� ������� ū ���
    else if (new_size > this->_size)
    {
        if (new_size > this->_capacity)
        {
            this->reserve(new_size * OVERFLOW_MULTIPLIER);
            for (SizeType i = this->_size - 1; i < new_size; ++i)
                *(this->_dptr + i) = init_val;
        }
        this->_size = new_size;
    }
    /// ���ο� ����� ���� ������� ���� ���
    else if (new_size < this->_size)
    {
        this->_size = new_size;
    }

    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::reserve(SizeType new_capacity)
{
    /// �� ĳ�۽�Ƽ�� ���� ĳ�۽�Ƽ�� ������ �� �� �ʿ䰡 ����
    if (new_capacity == this->_capacity) 
        return;

    else if (new_capacity < this->_capacity)
    {
        if (new_capacity < this->_size)
            this->_size = new_capacity;
    }

    DataType* t_dptr = new DataType[new_capacity];

    for (SizeType i = 0; i < this->_size; ++i)
        *(t_dptr + i) = *(this->_dptr + i);

    delete[] this->_dptr;

    this->_dptr = t_dptr;
    this->_capacity = new_capacity;

    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::assign(const DataType& new_val, SizeType new_size)
{
    this->resize(new_size);
    for (SizeType i = 0; i < this->_size; ++i)
        *(this->_dptr + i) = new_val;
    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::push_back(const DataType& push_val)
{
    this->resize(this->_size + 1);
    *(this->_dptr + this->_size - 1) = push_val;
    return;
}

#endif // _DYNAMIC_ARRAY_HPP
/// @file StaticArray.hpp
/// @author RZN

#ifndef _STATIC_ARRAY_HPP
#define _STATIC_ARRAY_HPP

#include "Array.hpp"

/// @class RStaticArray
/// @short ���� �迭 Ŭ����
template <typename DataType, SizeType Size>
class RStaticArray: 
    public RArray<DataType>
{
    using RLinear<DataType>::_size;
    using RLinear<DataType>::_capacity;
    using RLinear<DataType>::_dptr;

public: /* CONSTRUCTORS */
    RStaticArray();
    /// @short �ʱⰪ�� �ִ� ���� �迭 ������.
    /// @param[in] init_val �迭�� ��ü ��Ҹ� �� ������ �ʱ�ȭ�Ѵ�. 
    RStaticArray(const DataType& init_val);
    virtual ~RStaticArray() {};
public:
    void assign(const DataType& new_val, SizeType new_size) override;
private:
    DataType _data[Size];
};

template <typename DataType, SizeType Size>
RStaticArray<DataType, Size>::RStaticArray():
    RArray<DataType>(Size)
{
    this->_dptr = &_data[0];
    return;
}

template <typename DataType, SizeType Size>
RStaticArray<DataType, Size>::RStaticArray(const DataType& init_val): 
    RArray<DataType>(Size)
{
    this->_dptr = &_data[0];
    for (IndexType i = 0; i < this->_size; ++i)
        *(this->_dptr + i) = init_val;
    return;
}

template<typename DataType, SizeType Size>
inline void RStaticArray<DataType, Size>::assign(const DataType& new_val, SizeType new_size)
{
    if (new_size == this->_size)
    {
        for (SizeType i = 0; i < this->_size; ++i)
            *(this->_dptr + i) = new_val;
    }
    else if (new_size > this->_size)
    {
        for (SizeType i = 0; i < this->_size; ++i)
            *(this->_dptr + i) = new_val;
    }
    else if (new_size < this->_size)
    {
        for (SizeType i = 0; i < new_size; ++i)
            *(this->_dptr + i) = new_val;
    }
    return;
}

#endif // !_STATIC_ARRAY_HPP


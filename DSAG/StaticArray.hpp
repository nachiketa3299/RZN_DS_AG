/// @file StaticArray.hpp
/// @author RZN

#ifndef _STATIC_ARRAY_HPP
#define _STATIC_ARRAY_HPP

#include "Array.hpp"

/// @class RStaticArray
/// @short 정적 배열 클래스
template <typename DataType, SizeType Size>
class RStaticArray: 
    public RArray<DataType>
{
    using RLinear<DataType>::_size;
    using RLinear<DataType>::_capacity;
    using RLinear<DataType>::_dptr;

public: /* CONSTRUCTORS */
    RStaticArray();
    /// @short 초기값이 있는 정적 배열 생성자.
    /// @param[in] init_val 배열의 전체 요소를 이 값으로 초기화한다. 
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


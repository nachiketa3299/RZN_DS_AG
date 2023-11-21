/// @file StaticArray.hpp
/// @author RZN

#ifndef _STATIC_ARRAY_HPP
#define _STATIC_ARRAY_HPP

#include "Array.hpp"

namespace RArray
{
/// @class RArray::Static
/// @short 정적 배열 클래스
template <typename DataType, SizeType ArraySize>
class Static: 
    public RArray<DataType>
{
    using RLinear<DataType>::_size;
    using RLinear<DataType>::_capacity;
    using RLinear<DataType>::_dptr;

public: /* CONSTRUCTORS */
    Static();
    /// @short 초기값이 있는 정적 배열 생성자.
    /// @param[in] init_val 배열의 전체 요소를 이 값으로 초기화한다. 
    Static(const DataType& init_val);
    virtual ~Static() {};
public:
    void assign(const DataType& new_val, SizeType new_size) override;
private:
    DataType _data[ArraySize];
};
} // RArray


template <typename DataType, SizeType ArraySize>
RArray::Static<DataType, ArraySize>::Static():
    RArray<DataType>(ArraySize)
{
    this->_dptr = &_data[0];
    return;
}

template <typename DataType, SizeType ArraySize>
RArray::Static<DataType, ArraySize>::Static(const DataType& init_val): 
    RArray<DataType>(ArraySize)
{
    this->_dptr = &_data[0];
    for (IndexType i = 0; i < this->_size; ++i)
        *(this->_dptr + i) = init_val;
    return;
}

template<typename DataType, SizeType ArraySize>
void RArray::Static<DataType, ArraySize>::assign(const DataType& new_val, SizeType new_size)
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


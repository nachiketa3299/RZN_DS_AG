/// @file Linear.hpp
/// @author RZN

#ifndef _LINEAR_HPP
#define _LINEAR_HPP

#include "DSAG.h"
#include "Linear_Interface.h"

/// @class RLinear
/// @short 선형 자료구조의 부모
template <typename DataType>
class RLinear abstract:
    public RDSAG,
    public ILinear<DataType>
{
public:    /*! INTERFACE ILinear<DataType> */
    SizeType size() const override { return this->_size; };
    SizeType capacity() const override { return this->_capacity; };
    DataType& front() override { return *(this->_dptr + 0); };
    DataType& back() override { return *(this->_dptr + size() - 1); };
    bool empty() const override { return this->_size == 0 ? true : false; };

protected: /*! CONSTRUCTORS */
    RLinear();
    RLinear(SizeType init_size, SizeType init_capacity);
    virtual ~RLinear() {};

protected: /*! MEMBERS */
    SizeType _size;
    SizeType _capacity;
    DataType* _dptr;
};

template<typename DataType>
inline RLinear<DataType>::RLinear():
    _capacity(ZERO_SIZE),
    _size(ZERO_SIZE)
{}

template<typename DataType>
inline RLinear<DataType>::RLinear(SizeType init_size, SizeType init_capacity):
    _capacity(init_capacity),
    _size(init_size)
{}

#endif // !_LINEAR_HPP


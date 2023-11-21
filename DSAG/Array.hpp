/// @file Array.hpp
/// @author RZN

#ifndef _ARRAY_HPP
#define _ARRAY_HPP

#include "Linear.hpp"
#include "Iterator.hpp"
#include "Array_Interface.h"

#include <iostream>

/// @class RArray
/// @short ���� �迭�� ���� �迭�� �θ� �߻� Ŭ����
template <typename DataType>
class RArray abstract: 
    public RLinear<DataType>,
    public IArray<DataType>
{
public:
    using DataType = DataType;
    using Iterator = typename RRandomAccessIterator<RArray>;
public:
    using RLinear<DataType>::_size;
    using RLinear<DataType>::_capacity;

public:  /*! INTERFACE IPrintable (overrided) */
    void print_ds() const override;
    
public:  /*! INTERFACE IArray<DataType> */
    DataType& at(IndexType i) override { return *(this->_dptr + i); };
    DataType& operator[](IndexType i) override { return *(this->_dptr + i); };
    const DataType& get(IndexType i) const override { return *(this->_dptr + i); };
    void set(IndexType i, const DataType& v) override { *(this->_dptr + i) = v; }

public:
    /// @short 0�� �ε������� range-1 �� �ε������� value�� �����Ѵ�.
    /// @param[in] range
    /// @param[in] value
    virtual void assign(const DataType& new_val, SizeType new_size) abstract;

protected: /*! CONSTRUCTORS */
    RArray() {};
    RArray(SizeType init_size): RLinear<DataType>(init_size, init_size) {};
    RArray(SizeType init_size, SizeType init_capacity): RLinear<DataType>(init_size, init_capacity) {};
    virtual ~RArray() {};
};

template<typename DataType>
inline void RArray<DataType>::print_ds() const
{
    if (!this->_dptr) 
        return;

    using namespace std;
    cout << "===ARRAY(" << this->_size << ", " << this->_capacity << ")===\n";
    for (SizeType i = 0; i < this->size(); ++i)
        cout << *(this->_dptr + i) << ", ";
    cout << '\n';
}

#endif // !_ARRAY_HPP

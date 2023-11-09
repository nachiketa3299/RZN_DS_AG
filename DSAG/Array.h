/// @file Array.h
/// @author RZN

#ifndef _ARRAY_H
#define _ARRAY_H

#include "Array_Interface.h"
#include "Printable_Interface.h"

#include "DSAGTypes.h"

#include <iostream>

/// @class RArray
/// @short 동적 배열과 정적 배열의 부모 추상 클래스
template <typename DataType>
class RArray abstract: 
    public IArray<DataType>,
    public IPrintable
{
protected:
    RArray() {};
    virtual ~RArray() {};
public:
    DataType& at(IndexType i) override { return *(dptr + i); };
    DataType& operator[](IndexType i) override { return *(dptr + i); };
    const DataType& get(IndexType i) const override { return *(dptr + i); };
    void print_ds() const override;

    SizeType size() const abstract override;
protected:
    DataType* dptr;
};


template<typename DataType>
inline void RArray<DataType>::print_ds() const
{
    if (!dptr) 
        return;
    for (SizeType i = 0; i < this->size(); ++i)
        std::cout << *(dptr + i) << " ";
    std::cout << '\n';
}

#endif // !_ARRAY_H

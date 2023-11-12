/// @file Linear_Interface.h
/// @author RZN

#ifndef _LINEAR_INTERFACE_H
#define _LINEAR_INTERFACE_H

#include "DSAG_Types.h"

template <typename DataType>
class ILinear abstract
{
    /// @short 선형 자료구조의 크기를 반환
    virtual SizeType size() const abstract;

    /// @short 선형 자료구조의 용량을 반환
    virtual SizeType capacity() const abstract;

    /// @short 선령 자료구조의 최 좌측 값을 반환
    virtual DataType& front() abstract;

    /// @short 선형 자료구조의 최 우측 값을 반환
    virtual DataType& back() abstract;

    /// @short 선형 자료구조가 비어있는지의 여부를 반환
    virtual bool empty() const abstract;
};

#endif // !_LINEAR_INTERFACE_H



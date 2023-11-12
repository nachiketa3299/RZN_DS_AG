/// @file Linear_Interface.h
/// @author RZN

#ifndef _LINEAR_INTERFACE_H
#define _LINEAR_INTERFACE_H

#include "DSAG_Types.h"

template <typename DataType>
class ILinear abstract
{
    /// @short ���� �ڷᱸ���� ũ�⸦ ��ȯ
    virtual SizeType size() const abstract;

    /// @short ���� �ڷᱸ���� �뷮�� ��ȯ
    virtual SizeType capacity() const abstract;

    /// @short ���� �ڷᱸ���� �� ���� ���� ��ȯ
    virtual DataType& front() abstract;

    /// @short ���� �ڷᱸ���� �� ���� ���� ��ȯ
    virtual DataType& back() abstract;

    /// @short ���� �ڷᱸ���� ����ִ����� ���θ� ��ȯ
    virtual bool empty() const abstract;
};

#endif // !_LINEAR_INTERFACE_H



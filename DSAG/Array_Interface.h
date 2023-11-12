/// @file Array.h
/// @author RZN

#ifndef _ARRAY_INTERFACE_H
#define _ARRAY_INTERFACE_H

template<typename DataType>
class IArray abstract
{
public:
    /// @short i ��° ��Ҹ� ��ȯ
    virtual DataType& at(IndexType i) abstract;

    /// @short i ��° ��Ҹ� ��ȯ
    virtual DataType& operator[](IndexType i) abstract;

    /// @short i ��° ��Ҹ� ����� ��ȯ
    virtual const DataType& get(IndexType i) const  abstract;

    /// @short i ��° ��Ҹ� ���ڷ� ���޵� ������ ����
    virtual void set(IndexType i, const DataType& v) abstract;
};

#endif // _ARRAY_INTERFACE_H
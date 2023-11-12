/// @file Array.h
/// @author RZN

#ifndef _ARRAY_INTERFACE_H
#define _ARRAY_INTERFACE_H

template<typename DataType>
class IArray abstract
{
public:
    /// @short i 번째 요소를 반환
    virtual DataType& at(IndexType i) abstract;

    /// @short i 번째 요소를 반환
    virtual DataType& operator[](IndexType i) abstract;

    /// @short i 번째 요소를 상수로 반환
    virtual const DataType& get(IndexType i) const  abstract;

    /// @short i 번째 요소를 인자로 전달된 값으로 설정
    virtual void set(IndexType i, const DataType& v) abstract;
};

#endif // _ARRAY_INTERFACE_H
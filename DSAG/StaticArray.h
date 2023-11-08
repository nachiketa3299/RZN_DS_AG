/// @file StaticArray.h
/// @author RZN

#ifndef _STATIC_ARRAY_H
#define _STATIC_ARRAY_H

#include "DSAGTypes.h"

/// @class RStaticArray
/// @short 정적 배열 클래스
template <typename DataType, SizeType Size>
class RStaticArray
{
public:
    RStaticArray() {};
    /// @short 초기값이 있는 정적 배열 생성자.
    /// @param[in] init_val 배열의 전체 요소를 이 값으로 초기화한다. 
    RStaticArray(const DataType& init_val);

    /// @todo 유효하지 않은 인덱스에 대한 접근 요청이 들어오는 경우 처리하기
    /// @short 정적 배열 접근 연산
    /// @param[in] i 접근할 정적 배열 요소의 인덱스
    /// @return 인덱스에 해당하는 정적 배열 요소
    DataType& at(IndexType i);

    /// @short 정적 배열 접근 연산
    /// @param[in] i 접근할 정적 배열 요소의 인덱스
    /// @return 인덱스에 해당하는 정적 배열 요소
    DataType& operator[](IndexType i);

    /// @short 정적 배열 접근 연산. 접근만 가능하다.
    /// @param[in] i 접근할 정적 배열 요소의 인덱스
    /// @return 인덱스에 해당하는 정적 배열 요소
    const DataType& get(IndexType i) const;

    /// @short 정적 배열의 크기를 반환한다.
    /// @return 정적 배열의 크기
    SizeType size() const { return Size; };
private:
    /// @short 인자로 전달된 인덱스가 정적 배열 접근에 유효한지 검사한다.
    /// @param[in] i 검사할 인덱스
    /// @return 인자로 전달된 인덱스의 정적 배열 접근 유효성 여부
    bool is_valid_index(IndexType i) const { return (i < Size ? true : false); };
private:
    DataType data[Size];
};

template <typename DataType, SizeType Size>
RStaticArray<DataType, Size>::RStaticArray(const DataType& init_val)
{
    for (IndexType i = 0; i < Size; ++i)
        data[i] = init_val;
}

template <typename DataType, SizeType Size>
DataType& RStaticArray<DataType, Size>::at(IndexType i)
{
    return *(data + i);
}

template <typename DataType, SizeType Size>
DataType& RStaticArray<DataType, Size>::operator[](IndexType i)
{
    return *(data + i);
}

template <typename DataType, SizeType Size>
const DataType& RStaticArray<DataType, Size>::get(IndexType i) const
{
    return *(data + i);
}

#endif
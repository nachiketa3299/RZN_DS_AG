/// @file DynamicArray.hpp
/// @author RZN

#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP

#include "Array.hpp"

namespace RArray
{
/// @class RDyanmicArray
/// @short 동적 배열 클래스
template <typename DataType>
class Dynamic: 
    public RArray<DataType>
{
    using RLinear<DataType>::_size;
    using RLinear<DataType>::_capacity;
    using RLinear<DataType>::_dptr;

public:  /* CONSTRUCTORS */
    /// @short 아무 인자가 없는 동적 배열 생성자. 초기 캐퍼시티로 영역을 동적으로 할당함.
    Dynamic();

    /// @short 초기 크기만 받는 동적 배열 생성자.
    /// @param[in] size 생성할 동적 배열의 크기
    Dynamic(SizeType init_size);

    /// @short 초기값이 있는 동적 배열 생성자
    /// @param[in] size 생성할 동적 배열의 크기
    /// @param[in] init_val 생성할 동적 배열의 각 원소가 초기화될 값
    Dynamic(SizeType init_size, const DataType& init_val);

    virtual ~Dynamic() { delete[] this->_dptr; };

    SizeType capacity() const { return this->_capacity; };

    void resize(SizeType new_size);
    void resize(SizeType new_size, const DataType& init_val);
    void reserve(SizeType new_capacity);
    void assign(const DataType& new_val, SizeType new_size) override;
    void push_back(const DataType& push_val);
};
} // RArray


template <typename DataType>
RArray::Dynamic<DataType>::Dynamic():
    RArray<DataType>(ZERO_SIZE, INIT_CAPACITY)
{
    /// 동적 할당
    this->_dptr = new DataType[_capacity];
}

template<typename DataType>
RArray::Dynamic<DataType>::Dynamic(SizeType init_size)
{
    this->_size = init_size;
    if (this->_capacity < this->_size)
        this->_capacity = this->_size * OVERFLOW_MULTIPLIER;

    /// 동적 할당
    this->_dptr = new DataType[_capacity];
}

template <typename DataType>
RArray::Dynamic<DataType>::Dynamic(SizeType init_size, const DataType& init_val)
{
    this->_size = init_size;
    if (this->_capacity < this->_size)
        this->_capacity = this->_size * OVERFLOW_MULTIPLIER;

    /// 동적 할당
    this->_dptr = new DataType[_capacity];

    /// 초기 값 할당
    for (SizeType i = 0; i < _size; ++i)
        this->_dptr[i] = init_val;
    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::resize(SizeType new_size)
{
    /// 새로운 사이즈가 현재 사이즈와 같으면 뭘 할 필요가 없음
    if (new_size == this->_size)
        return;
    /// 새로운 사이즈가 현재 사이즈보다 큰 경우
    else if (new_size > this->_size)
    {
        if (new_size > this->_capacity)
            this->reserve(new_size * OVERFLOW_MULTIPLIER);
        this->_size = new_size;
    }
    /// 새로운 사이즈가 현재 사이즈보다 작은 경우
    else if (new_size < this->_size)
    {
        this->_size = new_size;
    }

    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::resize(SizeType new_size, const DataType& init_val)
{
    /// 새로운 사이즈가 현재 사이즈와 같으면 뭘 할 필요가 없음
    if (new_size == this->_size)
        return;
    /// 새로운 사이즈가 현재 사이즈보다 큰 경우
    else if (new_size > this->_size)
    {
        if (new_size > this->_capacity)
        {
            this->reserve(new_size * OVERFLOW_MULTIPLIER);
            for (SizeType i = this->_size - 1; i < new_size; ++i)
                *(this->_dptr + i) = init_val;
        }
        this->_size = new_size;
    }
    /// 새로운 사이즈가 현재 사이즈보다 작은 경우
    else if (new_size < this->_size)
    {
        this->_size = new_size;
    }

    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::reserve(SizeType new_capacity)
{
    /// 새 캐퍼시티와 현재 캐퍼시티가 같으면 뭘 할 필요가 없음
    if (new_capacity == this->_capacity) 
        return;

    else if (new_capacity < this->_capacity)
    {
        if (new_capacity < this->_size)
            this->_size = new_capacity;
    }

    DataType* t_dptr = new DataType[new_capacity];

    for (SizeType i = 0; i < this->_size; ++i)
        *(t_dptr + i) = *(this->_dptr + i);

    delete[] this->_dptr;

    this->_dptr = t_dptr;
    this->_capacity = new_capacity;

    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::assign(const DataType& new_val, SizeType new_size)
{
    this->resize(new_size);
    for (SizeType i = 0; i < this->_size; ++i)
        *(this->_dptr + i) = new_val;
    return;
}

template<typename DataType>
void RArray::Dynamic<DataType>::push_back(const DataType& push_val)
{
    this->resize(this->_size + 1);
    *(this->_dptr + this->_size - 1) = push_val;
    return;
}

#endif // _DYNAMIC_ARRAY_HPP
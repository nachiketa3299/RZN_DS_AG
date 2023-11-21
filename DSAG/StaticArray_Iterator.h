#ifndef DSAG_STATIC_ARRAY_ITERATOR_H
#define DSAG_STATIC_ARRAY_ITERATOR_H

#include "CoreDefinition.h"

_DSAG_BEGIN

template <typename T, size_t Size>
class StaticArray_Iterator
{
};

/*!
 * @class StaticArray_Iterator_Const
 * @brief ���� ���� ���� �迭�� ��� �ݺ���
 * @tparam T 
 * @tparam _Size 
*/
template <typename T, size_t Size>
class StaticArray_Iterator_Const
{
public:  /// [[ === TYPES === ]] 
    using ValueType_ = T;
    using PointerType_ = const T*;
public:
    /*!
     * @brief �⺻ ������
    */
    StaticArray_Iterator_Const() noexcept: ptr_(nullptr), index_(0) {};

    /*!
     * @brief �����͸� �޴� ������
     * @param ptr 
     * @param offset 
    */
    StaticArray_Iterator_Const(PointerType_ ptr, size_t offset = 0) noexcept: _ptr(ptr), _idx(offset) {};
public: /// [[ === OPERATOR OVERLOADINGS === ]] 
    /*!
     * @brief ���� ���� ������
     * @return 
    */
    constexpr StaticArray_Iterator_Const& operator++() noexcept
    {
        ++(this->index_);
        return *this;
    }
    /*!
     * @brief ���� ���� ������
     * @return 
    */
    constexpr StaticArray_Iterator_Const operator++(int) noexcept
    {
    }
    /*!
     * @brief ���� ���� ������
     * @return 
    */
    constexpr StaticArray_Iterator_Const& operator--() noexcept
    {
        --(this->index_);
        return *this;
    }
    /*!
     * @brief ���� ���� ������
     * @return 
    */
    constexpr StaticArray_Iterator_Const operator--(int) noexcept
    {
    }
    constexpr StaticArray_Iterator_Const& operator+=(const prtdiff_t offset) noexcept
    {
        return *this;
    }
    constexpr StaticArray_Iterator_Const& operator-=(const StaticArray_Const_Iterator& right) const noexcept
    {
        return *this;
    }
    constexpr ptrdiff_t operator-(const StaticArray_Iterator_Const& right) const noexcept
    {
        return static_cast<ptrdiff_t>(this->index_ - right.index_);
    }
    constexpr ValueType_& operator[](const ptrdiff_t offset) const noexcept
    {
        return *(*this + offset);
    }
    constexpr bool operator==(const StaticArray_Iterator_Const& right) const noexcept
    {
        return this->index_ == right.index_;
    }
    constexpr bool operator<(const StaticArray_Iterator_Const& right) const noexcept
    {
        return this->index_ < right.index_;
    }

public:
    constexpr void VerifyOffset(const ptrdiff_t offset) const noexcept
    {
        if (offset != 0)
        {

        }
        if (offset < 0)
        {

        }
        if (offset > 0)
        {

        }
    }
private:
    /// @short ���� �迭�� ���� �ּ�
    PointerType_ ptr_;
    /// @short ���� �迭�� ���ۿ��������� ������
    size_t index_;
};

_DSAG_END


#endif // !DSAG_STATIC_ARRAY_ITERATOR_H

/*!
 * @file StaticArray.h
 * @date 2023-11-25
*/

#ifndef DSAG_STATIC_ARRAY_H
#define DSAG_STATIC_ARRAY_H

#include "CoreDefinition.h"

#define DSAG_ARRAY_START_INDEX 0
#define DSAG_ARRAY_LAST_INDEX Size - 1
#define DSAG_ARRAY_LAST_RANGE Size
#define DSAG_ARRAY_STATIC_ACCESS_BODY_INDEX return this->elements[index];
#define DSAG_ARRAY_STATIC_ACCESS_BODY_FRONT return this->elements[0];
#define DSAG_ARRAY_STATIC_ACCESS_BODY_BACK return this->elements[Size - 1];

_DSAG_BEGIN

/*!
 * @class _StaticArray_Iterator
 * @short @ref StaticArray �� ���� �ݺ��� Ŭ����
 * @details Random-Access Iterator
*/
template <typename T, std::size_t Size>
class _StaticArray_Iterator
{
public: // Type Alias
    using ElementType = T;
    using SizeType = std::size_t;
public:
    constexpr _StaticArray_Iterator() noexcept:
        ptr(), offset(DSAG_ARRAY_START_INDEX)
    { }
    constexpr explicit _StaticArray_Iterator(ElementType* ptr, SizeType offset=DSAG_ARRAY_START_INDEX) noexcept:
        ptr(ptr), offset(offset)
    { }
public:
    _StaticArray_Iterator& operator++() noexcept
    {
        ++this->offset;
        return *this;
    }
    _StaticArray_Iterator operator++(int) noexcept
    {
        _StaticArray_Iterator temp = *this;
        ++(*this);
        return temp;
    } 
    _StaticArray_Iterator& operator--() noexcept
    {
        --this->offset;
        return *this;
    }
    _StaticArray_Iterator operator--(int) noexcept
    {
        _StaticArray_Iterator temp = *this;
        --(*this);
        return temp;
    }
    constexpr ElementType* operator->() const noexcept
    {

    }
private:
    ElementType* ptr;
    SizeType offset;
};

/// @short ���� ũ�� �迭�� ĸ��ȭ�ϴ� �����̳�
template <typename T, std::size_t Size>
class StaticArray
{
public: // Type Alias
    using ElementType = T;
    using SizeType = std::size_t;

    using Iterator = _StaticArray_Iterator<T, Size>;
    using ReverseIterator = int;

    using DifferenceType = std::ptrdiff_t;

public:
    /*!
     * @brief Default-Constructible
    */
    StaticArray() = default;

    /*!
     * @brief Copy-Constructible
     * @param right 
    */
    StaticArray(const StaticArray& right) 
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
            this->elements[i] = right[i];
        return;
    };

    /*!
     * @brief Copy-Assignable
     * @param right 
     * @return 
    */
    StaticArray& operator=(const StaticArray& right) 
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
            this->elements[i] = right[i];
        return *this;
    };

    /*!
     * @brief Move-Constructible
     * @param to_move 
    */
    StaticArray(const StaticArray&& to_move) noexcept
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
            this->elements[i] = to_move[i];
        return;
    };

    /*!
     * @brief Move-Assignable
     * @param to_move 
     * @return 
    */
    StaticArray& operator=(const StaticArray&& to_move) 
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
            this->elements[i] = to_move[i];
        return *this;
    };

    ~StaticArray() = default;

public:
    StaticArray(const T& to_fill) 
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
            this->elements[i] = to_fill;
        return;
    };

public: // Element Access
    /*!
     * @brief \p index �� ������ ��ġ�� ��ҿ� ���� ������ ��ȯ�Ѵ�.
     * @param[in] index ������ ����� �ε��� ��
     * @warning ��ȿ�� \p index ���� �˻����� �ʴ´�.
    */
    constexpr ElementType& operator[](SizeType index)
    {
        return this->elements[index];
    };

    /*!
     * @brief \p index �� ������ ��ġ�� ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
     * @param[in] index ������ ����� �ε��� ��
     * @warning ��ȿ�� \p index ���� �˻����� �ʴ´�.
    */
    constexpr const ElementType& operator[](SizeType index) const
    {
        return this->elements[index];
    };

    /*!
     * @brief \p index �� ������ ��ġ�� ��ҿ� ���� ������ ��ȯ�Ѵ�.
     * @param[in] index ������ ����� �ε��� ��
     * @note ��ȿ�� \p index ������ �˻��Ѵ�.   
    */
    constexpr ElementType& At(SizeType index) 
    { 
        assert(index >= 0 && index < Size);
        return this->elements[index]; 
    };

    /*!
     * @brief \p index �� ������ ��ġ�� ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
     * @param[in] index ������ ����� �ε��� ��
     * @note ��ȿ�� \p index ������ �˻��Ѵ�.   
    */
    constexpr const ElementType& At(SizeType index) const 
    { 
        assert(index >= 0 && index < Size);
        return this->elements[index]; 
    };

    /*!
     * @brief �����̳��� ù ��° ��ҿ� ���� ������ ��ȯ�Ѵ�.
     * @return �����̳��� ù ��° ���ҿ� ���� l-value ����
    */
    constexpr ElementType& Front() 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief �����̳��� ù ��° ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
     * @return �����̳��� ù ��° ���ҿ� ���� l-value ��� ����
    */
    constexpr const ElementType& Front() const 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief �����̳��� ������ ��ҿ� ���� ������ ��ȯ�Ѵ�.
     * @return �����̳��� ������ ���ҿ� ���� l-value ����
    */
    constexpr ElementType& Back() 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief �����̳��� ������ ���ҿ� ���� ��� ������ ��ȯ�Ѵ�.
     * @return �����̳��� ������ ���ҿ� ���� l-value ��� ����
    */
    constexpr const ElementType& Back() const 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief \p range_start �̻� \p range_end �̸��� ���Ҹ� \p to_fill �� ä���.
     * @param[in] to_fill ä�� ��
     * @param[in] range_start ä�� ������ ���� �ε���
     * @param[in] range_end ä�� ������ ������ �ε��� + 1
    */
    constexpr void FillRange(const ElementType& to_fill, SizeType range_start = DSAG_ARRAY_START_INDEX, SizeType range_end = Size)
    {
        for (SizeType i = range_start; i < range_end; ++i)
            this->elements[i] = to_fill;
        return;
    }

    /*!
     * @brief ���� �����̳��� ������ \p other �����̳��� ����� ��ü�Ѵ�.
     * @param other ���� �����̳ʿ� ��ü�� �����̳�
    */
    constexpr void Swap(StaticArray& other) noexcept
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
        {
            const auto temp = this->elements[i];
            this->elements[i] = other.elements[i];
            other.elements[i] = temp;
        }
        return;
    }

    /*!
     * @brief ���� �����̳��� ù ��° ���� �ּҸ� ��ȯ�Ѵ�.
     * @return ù ��° ������ �ּ�
    */
    constexpr ElementType* GetPtr() noexcept
    {
        return this->elements;
    }

    /*!
     * @brief ���� �����̳��� ũ�⸦ ��ȯ�Ѵ�.
     * @return ���� �����̳��� ũ��
    */
    constexpr SizeType GetSize() const noexcept
    {
        return Size;
    }
public:
    constexpr Iterator Begin() noexcept
    {
        return Iterator(this->elements, DSAG_ARRAY_START_INDEX);
    }
    constexpr Iterator End() noexcept
    {
        return Iterator(this->elements, DSAG_ARRAY_LAST_RANGE);
    }
private:
    ElementType elements[Size];
};

_DSAG_END


#endif // !DSAG_STATIC_ARRAY_H

#if 0
public: // Capacity
    constexpr bool Empty() {};
    /// @short ����� ������ ��ȯ�Ѵ�.
    constexpr size_t Size() {};
    /// @short ������ ����� �ִ� ������ ��ȯ�Ѵ�.
    constexpr size_t MaxSize() {};

public: // Operations
    /// @short �����̳��� ��� ���ҿ� \p value �� �Ҵ��Ѵ�.
    constexpr void Fill(const T& value) {};
    /// @short �����̳��� ������ \p other �� ��ü�Ѵ�. 
    /// @note Does not cause iterators and references to associate with the other container.
    constexpr void Swap(StaticArray& other) noexcept {};
public: // Iterators
    constexpr Iterator Begin() noexcept {};
    constexpr Iterator End() noexcept {};

    constexpr const Iterator ConstBegin() noexcept { return this->Begin(); };
    constexpr const Iterator ConstEnd() noexcept { return this->End(); };

    constexpr ReverseIterator ReverseBegin() noexcept {};
    constexpr ReverseIterator ReverseEnd() noexcept {};

    constexpr const ReverseIterator ConstReverseBegin() noexcept { return this->ReverseBegin(); };
    constexpr const ReverseIterator ConstReverseEnd() noexcept { return this->ReverseEnd(); };
#endif

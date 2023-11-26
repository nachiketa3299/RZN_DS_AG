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
 * @short @ref StaticArray 에 대한 반복자 클래스
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

/// @short 고정 크기 배열을 캡슐화하는 컨테이너
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
     * @brief \p index 로 지정된 위치의 요소에 대한 참조를 반환한다.
     * @param[in] index 접근할 요소의 인덱스 값
     * @warning 유효한 \p index 인지 검사하지 않는다.
    */
    constexpr ElementType& operator[](SizeType index)
    {
        return this->elements[index];
    };

    /*!
     * @brief \p index 로 지정된 위치의 요소에 대한 상수 참조를 반환한다.
     * @param[in] index 접근할 요소의 인덱스 값
     * @warning 유효한 \p index 인지 검사하지 않는다.
    */
    constexpr const ElementType& operator[](SizeType index) const
    {
        return this->elements[index];
    };

    /*!
     * @brief \p index 로 지정된 위치의 요소에 대한 참조를 반환한다.
     * @param[in] index 접근할 요소의 인덱스 값
     * @note 유효한 \p index 범위를 검사한다.   
    */
    constexpr ElementType& At(SizeType index) 
    { 
        assert(index >= 0 && index < Size);
        return this->elements[index]; 
    };

    /*!
     * @brief \p index 로 지정된 위치의 요소에 대한 상수 참조를 반환한다.
     * @param[in] index 접근할 요소의 인덱스 값
     * @note 유효한 \p index 범위를 검사한다.   
    */
    constexpr const ElementType& At(SizeType index) const 
    { 
        assert(index >= 0 && index < Size);
        return this->elements[index]; 
    };

    /*!
     * @brief 컨테이너의 첫 번째 요소에 대한 참조를 반환한다.
     * @return 컨테이너의 첫 번째 원소에 대한 l-value 참조
    */
    constexpr ElementType& Front() 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief 컨테이너의 첫 번째 요소에 대한 상수 참조를 반환한다.
     * @return 컨테이너의 첫 번째 원소에 대한 l-value 상수 참조
    */
    constexpr const ElementType& Front() const 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief 컨테이너의 마지막 요소에 대한 참조를 반환한다.
     * @return 컨테이너의 마지막 원소에 대한 l-value 참조
    */
    constexpr ElementType& Back() 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief 컨테이너의 마지막 원소에 대한 상수 참조를 반환한다.
     * @return 컨테이너의 마지막 원소에 대한 l-value 상수 참조
    */
    constexpr const ElementType& Back() const 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief \p range_start 이상 \p range_end 미만의 원소를 \p to_fill 로 채운다.
     * @param[in] to_fill 채울 값
     * @param[in] range_start 채울 범위의 시작 인덱스
     * @param[in] range_end 채울 범위의 마지막 인덱스 + 1
    */
    constexpr void FillRange(const ElementType& to_fill, SizeType range_start = DSAG_ARRAY_START_INDEX, SizeType range_end = Size)
    {
        for (SizeType i = range_start; i < range_end; ++i)
            this->elements[i] = to_fill;
        return;
    }

    /*!
     * @brief 현재 컨테이너의 내용을 \p other 컨테이너의 내용과 교체한다.
     * @param other 현재 컨테이너와 교체할 컨테이너
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
     * @brief 현재 컨테이너의 첫 번째 원소 주소를 반환한다.
     * @return 첫 번째 원소의 주소
    */
    constexpr ElementType* GetPtr() noexcept
    {
        return this->elements;
    }

    /*!
     * @brief 현재 컨테이너의 크기를 반환한다.
     * @return 현재 컨테이너의 크기
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
    /// @short 요소의 갯수를 반환한다.
    constexpr size_t Size() {};
    /// @short 가능한 요소의 최대 갯수를 반환한다.
    constexpr size_t MaxSize() {};

public: // Operations
    /// @short 컨테이너의 모든 원소에 \p value 를 할당한다.
    constexpr void Fill(const T& value) {};
    /// @short 컨테이너의 내용을 \p other 와 교체한다. 
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

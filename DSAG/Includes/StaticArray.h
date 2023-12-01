/*!
 * @file StaticArray.h
 * @date 2023-11-25
*/

#ifndef DSAG_STATIC_ARRAY_H
#define DSAG_STATIC_ARRAY_H

#include "CoreDefinition.h"

/*!
* @brief 배열의 시작 인덱스 정의
*/
#define DSAG_ARRAY_START_INDEX 0

/*!
* @brief 정적 배열의 종료 인덱스 정의
*/
#define DSAG_ARRAY_LAST_INDEX Size - 1

/*!
* @brief 정적 배열의 마지막 범위 정의. 정적 배열의 크기와 일치.
*/
#define DSAG_ARRAY_LAST_RANGE Size

/*!
* @brief 정적 배열의 인덱스 접근 함수 몸체
*/
#define DSAG_ARRAY_STATIC_ACCESS_BODY_INDEX return this->elements[index];

/*!
* @brief 정적 배열의 시작 원소 접근 함수 몸체
*/
#define DSAG_ARRAY_STATIC_ACCESS_BODY_FRONT return this->elements[0];

/*!
* @brief 정적 배열의 마지막 원소 접근 함수 몸체
*/
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
    /*!
     * @brief 정적 배열 반복자의 전위 증가 연산자 오버로딩
     * @return 본인에 대한 l-value 참조
    */
    _StaticArray_Iterator& operator++() noexcept
    {
        ++this->offset;
        return *this;
    }

    /*!
     * @brief 정적 배열 반복자의 후위 증가 연산자 오버로딩
     * @return 후위 증가 연산자에 의해 변경되기 이전 본인에 대한 pr-value 사본
    */
    _StaticArray_Iterator operator++(int) noexcept
    {
        _StaticArray_Iterator temp = *this;
        ++(*this);
        return temp;
    } 

    /*!
     * @brief 정적 배열 반복자의 전위 감소 연산자 오버로딩
     * @return 본인에 대한 l-value 참조
    */
    _StaticArray_Iterator& operator--() noexcept
    {
        --this->offset;
        return *this;
    }

    /*!
     * @brief 정적 배열 반복자의 후위 감소 연산자 오버로딩
     * @return 후위 감소 연산자에 의해 변경되기 이전 본인에 대한 pr-value 사본
    */
    _StaticArray_Iterator operator--(int) noexcept
    {
        _StaticArray_Iterator temp = *this;
        --(*this);
        return temp;
    }

    /*!
     * @brief 정적 배열 반복자의 포인터 멤버 접근 연산자(Pointer to Member) 오버로딩
     * @todo 제대로 이해하고 다시 주석을 달 필요가 있다.
    */
    constexpr ElementType* operator->() const noexcept
    {
        return this->ptr + this->offset;
    }

    constexpr bool operator==(const _StaticArray_Iterator& right) const noexcept
    {
        return this->offset == right.offset;
    }
    constexpr bool operator!=(const _StaticArray_Iterator& right) const noexcept
    {
        return this->offset != right.offset;
    }
    constexpr bool operator>(const _StaticArray_Iterator& right) const  noexcept
    {
        return this->offset > right.offset;
    }
    constexpr bool operator<(const _StaticArray_Iterator& right) const noexcept
    {
        return this->offset < right.offset;
    }
    constexpr ElementType& operator*() const noexcept
    {
        return *(this->operator->());
    }

private:
    ElementType* ptr;
    SizeType offset;
};

/*!
 * @short 정적 배열(고정 크기 배열, Static Array)을 캡슐화하는 컨테이너입니다.
 * @details 요소의 개수가 @p Size 개인 @p T 형 배열을 래핑합니다.
 * @tparam T 정적 배열의 각 요소의 자료형입니다.
 * @tparam Size 정적 배열의 크기(요소의 갯수)입니다.
 * @date 2023-12-01
*/
template <typename T, std::size_t Size>
class StaticArray
{
public: // Type Alias
    /*!
     * @brief 정적 배열의 각 요소의 자료형입니다.
     * @date 2023-12-01
    */
    using ElementType = T;

    /*!
     * @brief 정적 배열의 크기(요소의 갯수)입니다.
     * @date 2023-12-01
    */
    using SizeType = std::size_t;

    /*!
     * @brief 정적 배열의 정방향 순회 방법을 제공하는 반복자입니다.
     * @see @ref _StaticArray_Iterator
     * @date 2023-12-01
    */
    using Iterator = _StaticArray_Iterator<T, Size>;

    /*!
     * @brief 정적 배열의 역방향 순회 방법을 제공하는 반복자입니다.
     * @todo 구현되어 있지 않습니다.
     * @date 2023-12-01
    */
    using ReverseIterator = int;

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

    /*!
     * @brief 정적 배열의 소멸자(Destructor)입니다.
     * @date 2023-12-01
    */
    ~StaticArray() = default;

public:
    /*!
     * @brief 정적 배열을 선언과 동시에 모든 요소를 @p to_fill 값으로 설정합니다.
     * @param to_fill 정적 배열의 모든 요소가 이 값으로 초기화 됩니다.
     * @date 2023-12-01
    */
    StaticArray(const T& to_fill) 
    {
        for (SizeType i = DSAG_ARRAY_START_INDEX; i < DSAG_ARRAY_LAST_RANGE; ++i)
            this->elements[i] = to_fill;
        return;
    };

public: // Element Access
    /*!
     * @copybrief StaticArray::At(SizeType)
     * @note 정적 배열의 아래 첨자 연산자(Subscript Operator, `[]`)에 대한 오버로딩입니다.
     * @param[in] index 접근할 요소의 인덱스 값입니다.
     * @return @p index 로 지정된 위치의 요소에 대한 참조(l-value) 입니다.
     * @warning @p index 의 유효성을 검사하지 않습니다. @p index 의 유효성을 검사하고 싶으면 @ref StaticArray::At(SizeType) 을 사용하십시오.
     * @date 2023-12-01
    */
    constexpr ElementType& operator[](SizeType index)
    {
        return this->elements[index];
    };

    /*!
     * @copybrief StaticArray::At(SizeType) const
     * @note 정적 배열의 아래 첨자 연산자(Subscript Operator, `[]`)에 대한 오버로딩입니다.
     * @param[in] index 접근할 요소의 인덱스 값입니다.
     * @return @p index 로 지정된 위치의 요소에 대한 상수 참조(l-value) 입니다.
     * @warning @p index 의 유효성을 검사하지 않습니다. @p index 의 유효성을 검사하고 싶으면 @ref StaticArray::At(SizeType) const 을 사용하십시오.
     * @date 2023-12-01
    */
    constexpr const ElementType& operator[](SizeType index) const
    {
        return this->elements[index];
    };

    /*!
     * @brief 정적 배열의 @p index 로 지정된 위치의 요소에 대한 참조(l-value)를 반환합니다.
     * @param[in] index 접근할 요소의 인덱스 값입니다.
     * @return @p index 로 지정된 위치의 요소에 대한 참조(l-value) 입니다.
     * @note @p index 의 유효성을 검사합니다.
     * @date 2023-12-01
    */
    constexpr ElementType& At(SizeType index) 
    { 
        assert(StaticArray::IsValidIndex(index), "유효하지 않은 index 입니다.");
        return this->elements[index]; 
    };

    /*!
     * @brief 정적 배열의 \p index 로 지정된 위치의 요소에 대한 상수 참조(l-value)를 반환합니다.
     * @param[in] index 접근할 요소의 인덱스 값입니다.
     * @return \p index 로 지정된 위치의 요소에 대한 상수 참조(l-value) 입니다.
     * @note \p index 의 유효성을 검사합니다.
     * @date 2023-12-01
    */
    constexpr const ElementType& At(SizeType index) const 
    { 
        assert(StaticArray::IsValidIndex(index), "유효하지 않은 index 입니다.");
        return this->elements[index]; 
    };

    /*!
     * @brief 정적 배열의 첫 번째 요소에 대한 참조(l-value)를 반환합니다.
     * @return 첫 번째 요소에 대한 참조(l-value)입니다.
     * @date 2023-12-01
    */
    constexpr ElementType& Front() 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief 정적 배열의 첫 번째 요소에 대한 상수 참조(l-value)를 반환합니다.
     * @return 첫 번째 원소에 대한 상수 참조(l-value)입니다.
     * @date 2023-12-01
    */
    constexpr const ElementType& Front() const 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief 정적 배열의 마지막 요소에 대한 참조(l-value)를 반환합니다.
     * @return 마지막 요소에 대한 참조(l-value)입니다.
     * @date 2023-12-01
    */
    constexpr ElementType& Back() 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief 정적 배열의 마지막 요소에 대한 상수 참조(l-value)를 반환합니다.
     * @return 마지막 요소에 대한 상수 참조(l-value)입니다.
     * @date 2023-12-01
    */
    constexpr const ElementType& Back() const 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief 정적 배열의 @p range_start_index 이상 @p range_last 미만의 요소를 값 @p to_fill 로 채웁니다(Fill).
     * @details
     * @p range_start_index 와 @p range_last 는 다음을 만족해야 합니다:
     * @f(
     * 0 \leq \verb|range_start_index| < \verb|range_last| \leq \verb|Size|
     * @f)
     * @param[in] to_fill 설정할 값 입니다.
     * @param[in] range_start_index (Optional) 채울 범위의 시작 인덱스 입니다. 기본 값은 #DSAG_ARRAY_START_INDEX 입니다.
     * @param[in] range_last (Optional) 채울 범위의 끝 입니다. 채울 범위의 마지막 인덱스에 1을 더한 값입니다. 기본 값은 @p Size 입니다.
     * @todo 반복자 버전의 오버로딩이 필요하다.
     * @date 2023-12-01
    */
    constexpr void FillRange(const ElementType& to_fill, SizeType range_start_index = DSAG_ARRAY_START_INDEX, SizeType range_last = Size)
    {
        assert(StaticArray::IsValidIndex(range_start_index), "range_start_index 가 유효한 인덱스가 아닙니다.");
        assert(range_last <= Size, "range_last 가 정적 배열의 범위를 벗어납니다.");
        assert(range_start_index < range_last, "range_last는 항상 range_start_index 보다 커야 합니다.");

        for (SizeType i = range_start_index; i < range_last; ++i)
            this->elements[i] = to_fill;
        return;
    }

    /*!
     * @brief 현재 정적 배열의 내용을 다른 정적 배열의 내용(\p other )과 교체(Swap)합니다.
     * @param other 교체할 다른 정적 배열에 대한 참조(l-value)입니다.
     * @date 2023-12-01
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
     * @brief 정적 배열의 첫 번째 요소에 대한 포인터를 반환합니다.
     * @return 정적 배열의 첫 번째 요소에 대한 포인터입니다.
     * @date 2023-12-01
    */
    constexpr ElementType* GetPtr() noexcept
    {
        return this->elements;
    }

    /*!
     * @brief 정적 배열의 크기를 반환합니다.
     * @return 정적 배열의 크기(\p Size )입니다.
     * @date 2023-12-01
    */
    constexpr SizeType GetSize() const noexcept
    {
        return Size;
    }

    /*!
     * @brief \p index 를 받아, 유효한 인덱스인지 검사합니다.
     * @note 0 이상, #Size 미만의 \p index 를 *유효하다(Valid)* 라고 정의합니다.
     * @param index 검사할 인덱스 값입니다.
     * @return \p index 가 유효한 인덱스면 참(true), 유효하지 않으면 거짓(false)입니다.
     * @date 2023-12-01
    */
    inline static constexpr bool IsValidIndex(SizeType index)
    {
        return (0 <= index && index < Size);
    }

public:
    /*!
     * @brief 현재 컨테이너의 시작 반복자를 반환
     * @return 현재 컨테이너의 시작 반복자
     * @relatesalso @ref _StaticArray_Iterator
    */
    constexpr Iterator Begin() noexcept
    {
        return Iterator(this->elements, DSAG_ARRAY_START_INDEX);
    }

    /*!
     * @brief 현재 컨테이너의 끝 반복자를 반환
     * @return 현재 컨테이너의 끝 반복자
     * @relatesalso @ref _StaticArray_Iterator
    */
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

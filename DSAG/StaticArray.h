/*!
 * @file StaticArray.h
 * @date 2023-11-19
*/

#ifndef DSAG_STATIC_ARRAY_H
#define DSAG_STATIC_ARRAY_H

#include "CoreDefinition.h"
#include <cstddef>
#include <array>

std::array<int, 3> fuck;

_DSAG_BEGIN

class StaticArray_Iterator
{
};

/// @short 고정 크기 배열을 캡슐화하는 컨테이너
template <typename T, std::size_t Size>
class StaticArray
{
public: // Type Alias
    using ElementType = T;
    using SizeType = std::size_t;

    using Iterator = int;
    using ReverseIterator = int;

    using DifferenceType = std::ptrdiff_t;

public: // ctor, dtor
    StaticArray() = default;
    StaticArray(const StaticArray& right) {};
    StaticArray& operator=(const StaticArray& right) {};
    StaticArray(const StaticArray&& to_move) {};
    StaticArray& operator=(const StaticArray&& to_move) {};
    ~StaticArray() = default;
    StaticArray& operator=(const StaticArray&) = default;

public:
    StaticArray(const T& to_fill) {};

public: // Element Access
#ifndef DSAG_STATIC_ARRAY_ACCESS_BODY
#define DSAG_STATIC_ARRAY_ACCESS_BODY return this->elements[index];
#endif
    /// @brief \p index 로 지정된 위치의 요소에 대한 참조를 반환한다.
    /// @warning 유효한 \p index 인지는 검사하지 않는다.
    constexpr       ElementType& operator[](SizeType index) { DSAG_STATIC_ARRAY_ACCESS_BODY };
    /// @brief \p index 로 지정된 위치의 요소에 대한 상수 참조를 반환한다.
    /// @warning 유효한 \p index 인지는 검사하지 않는다.
    constexpr const ElementType& operator[](SizeType index) const { DSAG_STATIC_ARRAY_ACCESS_BODY };

    /// @brief \p index 로 지정된 위치의 요소에 대한 참조를 반환한다.
    /// @note 유효한 \p index 범위를 검사한다.   
    constexpr       ElementType& At(SizeType index) { DSAG_STATIC_ARRAY_ACCESS_BODY };
    /// @brief \p index 로 지정된 위치의 요소에 대한 상수 참조를 반환한다.
    /// @note 유효한 \p index 범위를 검사한다.   
    constexpr const ElementType& At(SizeType index) const { DSAG_STATIC_ARRAY_ACCESS_BODY };

#ifndef DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY
#define DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY return this->elements[0];
#endif
    /// @brief 컨테이너의 첫 번째 요소에 대한 참조를 반환한다.
    constexpr ElementType& Front() { DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY };
    /// @brief 컨테이너의 첫 번째 요소에 대한 상수 참조를 반환한다.
    constexpr const ElementType& Front() const { DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY };

#ifndef DSAG_STATIC_ARRAY_ACCESS_BACK_BODY
#define DSAG_STATIC_ARRAY_ACCESS_BACK_BODY return this->elements[Size - 1];
#endif
    /// @brief 컨테이너의 마지막 요소에 대한 참조를 반환한다.
    constexpr ElementType& Back() { DSAG_STATIC_ARRAY_ACCESS_BACK_BODY };
    /// @brief 컨테이너의 마지막 요소에 대한 상수 참조를 반환한다.
    constexpr const ElementType& Back() const {};

    // constexpr Data

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
private:
    ElementType elements[Size];
};

_DSAG_END


#endif // !DSAG_STATIC_ARRAY_H

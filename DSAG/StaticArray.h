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

/// @short ���� ũ�� �迭�� ĸ��ȭ�ϴ� �����̳�
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
    /// @brief \p index �� ������ ��ġ�� ��ҿ� ���� ������ ��ȯ�Ѵ�.
    /// @warning ��ȿ�� \p index ������ �˻����� �ʴ´�.
    constexpr       ElementType& operator[](SizeType index) { DSAG_STATIC_ARRAY_ACCESS_BODY };
    /// @brief \p index �� ������ ��ġ�� ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
    /// @warning ��ȿ�� \p index ������ �˻����� �ʴ´�.
    constexpr const ElementType& operator[](SizeType index) const { DSAG_STATIC_ARRAY_ACCESS_BODY };

    /// @brief \p index �� ������ ��ġ�� ��ҿ� ���� ������ ��ȯ�Ѵ�.
    /// @note ��ȿ�� \p index ������ �˻��Ѵ�.   
    constexpr       ElementType& At(SizeType index) { DSAG_STATIC_ARRAY_ACCESS_BODY };
    /// @brief \p index �� ������ ��ġ�� ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
    /// @note ��ȿ�� \p index ������ �˻��Ѵ�.   
    constexpr const ElementType& At(SizeType index) const { DSAG_STATIC_ARRAY_ACCESS_BODY };

#ifndef DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY
#define DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY return this->elements[0];
#endif
    /// @brief �����̳��� ù ��° ��ҿ� ���� ������ ��ȯ�Ѵ�.
    constexpr ElementType& Front() { DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY };
    /// @brief �����̳��� ù ��° ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
    constexpr const ElementType& Front() const { DSAG_STATIC_ARRAY_ACCESS_FRONT_BODY };

#ifndef DSAG_STATIC_ARRAY_ACCESS_BACK_BODY
#define DSAG_STATIC_ARRAY_ACCESS_BACK_BODY return this->elements[Size - 1];
#endif
    /// @brief �����̳��� ������ ��ҿ� ���� ������ ��ȯ�Ѵ�.
    constexpr ElementType& Back() { DSAG_STATIC_ARRAY_ACCESS_BACK_BODY };
    /// @brief �����̳��� ������ ��ҿ� ���� ��� ������ ��ȯ�Ѵ�.
    constexpr const ElementType& Back() const {};

    // constexpr Data

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
private:
    ElementType elements[Size];
};

_DSAG_END


#endif // !DSAG_STATIC_ARRAY_H

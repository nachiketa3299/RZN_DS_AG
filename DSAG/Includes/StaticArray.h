/*!
 * @file StaticArray.h
 * @date 2023-11-25
*/

#ifndef DSAG_STATIC_ARRAY_H
#define DSAG_STATIC_ARRAY_H

#include "CoreDefinition.h"

/*!
* @brief �迭�� ���� �ε��� ����
*/
#define DSAG_ARRAY_START_INDEX 0

/*!
* @brief ���� �迭�� ���� �ε��� ����
*/
#define DSAG_ARRAY_LAST_INDEX Size - 1

/*!
* @brief ���� �迭�� ������ ���� ����. ���� �迭�� ũ��� ��ġ.
*/
#define DSAG_ARRAY_LAST_RANGE Size

/*!
* @brief ���� �迭�� �ε��� ���� �Լ� ��ü
*/
#define DSAG_ARRAY_STATIC_ACCESS_BODY_INDEX return this->elements[index];

/*!
* @brief ���� �迭�� ���� ���� ���� �Լ� ��ü
*/
#define DSAG_ARRAY_STATIC_ACCESS_BODY_FRONT return this->elements[0];

/*!
* @brief ���� �迭�� ������ ���� ���� �Լ� ��ü
*/
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
    /*!
     * @brief ���� �迭 �ݺ����� ���� ���� ������ �����ε�
     * @return ���ο� ���� l-value ����
    */
    _StaticArray_Iterator& operator++() noexcept
    {
        ++this->offset;
        return *this;
    }

    /*!
     * @brief ���� �迭 �ݺ����� ���� ���� ������ �����ε�
     * @return ���� ���� �����ڿ� ���� ����Ǳ� ���� ���ο� ���� pr-value �纻
    */
    _StaticArray_Iterator operator++(int) noexcept
    {
        _StaticArray_Iterator temp = *this;
        ++(*this);
        return temp;
    } 

    /*!
     * @brief ���� �迭 �ݺ����� ���� ���� ������ �����ε�
     * @return ���ο� ���� l-value ����
    */
    _StaticArray_Iterator& operator--() noexcept
    {
        --this->offset;
        return *this;
    }

    /*!
     * @brief ���� �迭 �ݺ����� ���� ���� ������ �����ε�
     * @return ���� ���� �����ڿ� ���� ����Ǳ� ���� ���ο� ���� pr-value �纻
    */
    _StaticArray_Iterator operator--(int) noexcept
    {
        _StaticArray_Iterator temp = *this;
        --(*this);
        return temp;
    }

    /*!
     * @brief ���� �迭 �ݺ����� ������ ��� ���� ������(Pointer to Member) �����ε�
     * @todo ����� �����ϰ� �ٽ� �ּ��� �� �ʿ䰡 �ִ�.
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
 * @short ���� �迭(���� ũ�� �迭, Static Array)�� ĸ��ȭ�ϴ� �����̳��Դϴ�.
 * @details ����� ������ @p Size ���� @p T �� �迭�� �����մϴ�.
 * @tparam T ���� �迭�� �� ����� �ڷ����Դϴ�.
 * @tparam Size ���� �迭�� ũ��(����� ����)�Դϴ�.
 * @date 2023-12-01
*/
template <typename T, std::size_t Size>
class StaticArray
{
public: // Type Alias
    /*!
     * @brief ���� �迭�� �� ����� �ڷ����Դϴ�.
     * @date 2023-12-01
    */
    using ElementType = T;

    /*!
     * @brief ���� �迭�� ũ��(����� ����)�Դϴ�.
     * @date 2023-12-01
    */
    using SizeType = std::size_t;

    /*!
     * @brief ���� �迭�� ������ ��ȸ ����� �����ϴ� �ݺ����Դϴ�.
     * @see @ref _StaticArray_Iterator
     * @date 2023-12-01
    */
    using Iterator = _StaticArray_Iterator<T, Size>;

    /*!
     * @brief ���� �迭�� ������ ��ȸ ����� �����ϴ� �ݺ����Դϴ�.
     * @todo �����Ǿ� ���� �ʽ��ϴ�.
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
     * @brief ���� �迭�� �Ҹ���(Destructor)�Դϴ�.
     * @date 2023-12-01
    */
    ~StaticArray() = default;

public:
    /*!
     * @brief ���� �迭�� ����� ���ÿ� ��� ��Ҹ� @p to_fill ������ �����մϴ�.
     * @param to_fill ���� �迭�� ��� ��Ұ� �� ������ �ʱ�ȭ �˴ϴ�.
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
     * @note ���� �迭�� �Ʒ� ÷�� ������(Subscript Operator, `[]`)�� ���� �����ε��Դϴ�.
     * @param[in] index ������ ����� �ε��� ���Դϴ�.
     * @return @p index �� ������ ��ġ�� ��ҿ� ���� ����(l-value) �Դϴ�.
     * @warning @p index �� ��ȿ���� �˻����� �ʽ��ϴ�. @p index �� ��ȿ���� �˻��ϰ� ������ @ref StaticArray::At(SizeType) �� ����Ͻʽÿ�.
     * @date 2023-12-01
    */
    constexpr ElementType& operator[](SizeType index)
    {
        return this->elements[index];
    };

    /*!
     * @copybrief StaticArray::At(SizeType) const
     * @note ���� �迭�� �Ʒ� ÷�� ������(Subscript Operator, `[]`)�� ���� �����ε��Դϴ�.
     * @param[in] index ������ ����� �ε��� ���Դϴ�.
     * @return @p index �� ������ ��ġ�� ��ҿ� ���� ��� ����(l-value) �Դϴ�.
     * @warning @p index �� ��ȿ���� �˻����� �ʽ��ϴ�. @p index �� ��ȿ���� �˻��ϰ� ������ @ref StaticArray::At(SizeType) const �� ����Ͻʽÿ�.
     * @date 2023-12-01
    */
    constexpr const ElementType& operator[](SizeType index) const
    {
        return this->elements[index];
    };

    /*!
     * @brief ���� �迭�� @p index �� ������ ��ġ�� ��ҿ� ���� ����(l-value)�� ��ȯ�մϴ�.
     * @param[in] index ������ ����� �ε��� ���Դϴ�.
     * @return @p index �� ������ ��ġ�� ��ҿ� ���� ����(l-value) �Դϴ�.
     * @note @p index �� ��ȿ���� �˻��մϴ�.
     * @date 2023-12-01
    */
    constexpr ElementType& At(SizeType index) 
    { 
        assert(StaticArray::IsValidIndex(index), "��ȿ���� ���� index �Դϴ�.");
        return this->elements[index]; 
    };

    /*!
     * @brief ���� �迭�� \p index �� ������ ��ġ�� ��ҿ� ���� ��� ����(l-value)�� ��ȯ�մϴ�.
     * @param[in] index ������ ����� �ε��� ���Դϴ�.
     * @return \p index �� ������ ��ġ�� ��ҿ� ���� ��� ����(l-value) �Դϴ�.
     * @note \p index �� ��ȿ���� �˻��մϴ�.
     * @date 2023-12-01
    */
    constexpr const ElementType& At(SizeType index) const 
    { 
        assert(StaticArray::IsValidIndex(index), "��ȿ���� ���� index �Դϴ�.");
        return this->elements[index]; 
    };

    /*!
     * @brief ���� �迭�� ù ��° ��ҿ� ���� ����(l-value)�� ��ȯ�մϴ�.
     * @return ù ��° ��ҿ� ���� ����(l-value)�Դϴ�.
     * @date 2023-12-01
    */
    constexpr ElementType& Front() 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief ���� �迭�� ù ��° ��ҿ� ���� ��� ����(l-value)�� ��ȯ�մϴ�.
     * @return ù ��° ���ҿ� ���� ��� ����(l-value)�Դϴ�.
     * @date 2023-12-01
    */
    constexpr const ElementType& Front() const 
    { 
        return this->elements[DSAG_ARRAY_START_INDEX]; 
    };

    /*!
     * @brief ���� �迭�� ������ ��ҿ� ���� ����(l-value)�� ��ȯ�մϴ�.
     * @return ������ ��ҿ� ���� ����(l-value)�Դϴ�.
     * @date 2023-12-01
    */
    constexpr ElementType& Back() 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief ���� �迭�� ������ ��ҿ� ���� ��� ����(l-value)�� ��ȯ�մϴ�.
     * @return ������ ��ҿ� ���� ��� ����(l-value)�Դϴ�.
     * @date 2023-12-01
    */
    constexpr const ElementType& Back() const 
    { 
        return this->elements[DSAG_ARRAY_LAST_INDEX]; 
    };

    /*!
     * @brief ���� �迭�� @p range_start_index �̻� @p range_last �̸��� ��Ҹ� �� @p to_fill �� ä��ϴ�(Fill).
     * @details
     * @p range_start_index �� @p range_last �� ������ �����ؾ� �մϴ�:
     * @f(
     * 0 \leq \verb|range_start_index| < \verb|range_last| \leq \verb|Size|
     * @f)
     * @param[in] to_fill ������ �� �Դϴ�.
     * @param[in] range_start_index (Optional) ä�� ������ ���� �ε��� �Դϴ�. �⺻ ���� #DSAG_ARRAY_START_INDEX �Դϴ�.
     * @param[in] range_last (Optional) ä�� ������ �� �Դϴ�. ä�� ������ ������ �ε����� 1�� ���� ���Դϴ�. �⺻ ���� @p Size �Դϴ�.
     * @todo �ݺ��� ������ �����ε��� �ʿ��ϴ�.
     * @date 2023-12-01
    */
    constexpr void FillRange(const ElementType& to_fill, SizeType range_start_index = DSAG_ARRAY_START_INDEX, SizeType range_last = Size)
    {
        assert(StaticArray::IsValidIndex(range_start_index), "range_start_index �� ��ȿ�� �ε����� �ƴմϴ�.");
        assert(range_last <= Size, "range_last �� ���� �迭�� ������ ����ϴ�.");
        assert(range_start_index < range_last, "range_last�� �׻� range_start_index ���� Ŀ�� �մϴ�.");

        for (SizeType i = range_start_index; i < range_last; ++i)
            this->elements[i] = to_fill;
        return;
    }

    /*!
     * @brief ���� ���� �迭�� ������ �ٸ� ���� �迭�� ����(\p other )�� ��ü(Swap)�մϴ�.
     * @param other ��ü�� �ٸ� ���� �迭�� ���� ����(l-value)�Դϴ�.
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
     * @brief ���� �迭�� ù ��° ��ҿ� ���� �����͸� ��ȯ�մϴ�.
     * @return ���� �迭�� ù ��° ��ҿ� ���� �������Դϴ�.
     * @date 2023-12-01
    */
    constexpr ElementType* GetPtr() noexcept
    {
        return this->elements;
    }

    /*!
     * @brief ���� �迭�� ũ�⸦ ��ȯ�մϴ�.
     * @return ���� �迭�� ũ��(\p Size )�Դϴ�.
     * @date 2023-12-01
    */
    constexpr SizeType GetSize() const noexcept
    {
        return Size;
    }

    /*!
     * @brief \p index �� �޾�, ��ȿ�� �ε������� �˻��մϴ�.
     * @note 0 �̻�, #Size �̸��� \p index �� *��ȿ�ϴ�(Valid)* ��� �����մϴ�.
     * @param index �˻��� �ε��� ���Դϴ�.
     * @return \p index �� ��ȿ�� �ε����� ��(true), ��ȿ���� ������ ����(false)�Դϴ�.
     * @date 2023-12-01
    */
    inline static constexpr bool IsValidIndex(SizeType index)
    {
        return (0 <= index && index < Size);
    }

public:
    /*!
     * @brief ���� �����̳��� ���� �ݺ��ڸ� ��ȯ
     * @return ���� �����̳��� ���� �ݺ���
     * @relatesalso @ref _StaticArray_Iterator
    */
    constexpr Iterator Begin() noexcept
    {
        return Iterator(this->elements, DSAG_ARRAY_START_INDEX);
    }

    /*!
     * @brief ���� �����̳��� �� �ݺ��ڸ� ��ȯ
     * @return ���� �����̳��� �� �ݺ���
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

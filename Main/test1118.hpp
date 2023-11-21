/// @file test1118.hpp
/// @author RZN

#ifndef _TEST_1118_HPP
#define _TEST_1118_HPP

/*!
* @class SArray
* @short ���ø�ȭ�� ���� �迭 Ŭ����
* @param[in] T �迭 ����� �ڷ���
* @param[in] ArraySize ���� �迭�� ũ��
*/
template <typename T, size_t ArraySize>
class SArray
{
public:
    /*!
    * @note �⺻ ������(Default Constructor)
    * @brief ������ ������ �迭�� �ʱ�ȭ��
    */
    SArray();

    /*!
    * @brief Ư�� ������ �迭�� �ʱ�ȭ�ϴ� ������
    * @param[in] init_val �迭 ��Ҹ� �� ������ ��� �ʱ�ȭ�Ѵ�.
    */
    SArray(const T& init_val);

    /*!
    * @note ���� ������(Copy Constructor)
    * @brief �ٸ� ���� �迭�� ���� ������ ������ ���� �迭�� �ʱ�ȭ�Ѵ�.
    * @param from ������ ���� �迭
    */
    SArray(const SArray<T, ArraySize>& from);

    /*!
    * @note ���� ���� ������(Copy Assignment Operator)
    * @brief 
    * @param from 
    * @return 
    */
    SArray<T, ArraySize>& operator=(SArray<T, ArraySize>& from);

    /*!
    * @note �̵� ������(Move Constructor)
    * @brief 
    * @param from 
    */
    SArray(SArray<T, ArrSize>&& from) noexcept;

    /*!
    * @note �̵� ���� ������(Move Assignment Constructor)
    * @brief 
    * @param from 
    * @return 
    */
    SArray<T, ArraySize>& operator=(SArray<T, ArraySize>&& from);

    virtual ~SArray();

    /*!
     * @brief �Ʒ� ÷�� ������([]) �����ε�. �ε����� �ش��ϴ� �迭 ���� �����Ѵ�. ���� ������ ��ȯ�Ѵ�.
     * @warning �ε����� ��ȿ������ �˻����� �ʴ´�.
     * @param index ������ �迭 ����� �ε���
     * @return �ε����� �ش��ϴ� �迭 ��ҿ� ���� ���� ��
    */
    T& operator[](size_t index);
private:
    size_t _size;
    T _data[ArraySize];
};

template<typename T, size_t ArraySize>
inline SArray<T, ArraySize>::SArray(): _size(ArraySize)
{
    return;
}

template<typename T, size_t ArraySize>
inline SArray<T, ArraySize>::SArray(const T& init_val): _size(ArraySize)
{
    for (size_t i = 0; i < this->_size; ++i)
        *(this->_data + i) = init_val;
    return;
}

template<typename T, size_t ArraySize>
inline SArray<T, ArraySize>::SArray(const SArray<T, ArraySize>& from)
{
}

template<typename T, size_t ArraySize>
inline SArray<T,ArraySize> & SArray<T, ArraySize>::operator=(SArray<T, ArraySize>& from)
{
    // TODO: insert return statement here
}

template<typename T, size_t ArraySize>
inline SArray<T, ArraySize>::SArray(SArray<T, ArrSize>&& from) noexcept
{
}

template<typename T, size_t ArraySize>
inline SArray<T, ArraySize>& SArray<T, ArraySize>::operator=(SArray<T, ArraySize>&& from)
{
    return *this
}

template<typename T, size_t ArraySize>
inline T& SArray<T, ArraySize>::operator[](size_t index)
{
    return this->_data[index];
}

#endif // !_TEST_1118_HPP


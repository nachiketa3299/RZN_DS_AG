/// @file test1118.hpp
/// @author RZN

#ifndef _TEST_1118_HPP
#define _TEST_1118_HPP

/*!
* @class SArray
* @short 템플릿화된 정적 배열 클래스
* @param[in] T 배열 요소의 자료형
* @param[in] ArraySize 정적 배열의 크기
*/
template <typename T, size_t ArraySize>
class SArray
{
public:
    /*!
    * @note 기본 생성자(Default Constructor)
    * @brief 쓰레기 값으로 배열을 초기화함
    */
    SArray();

    /*!
    * @brief 특정 값으로 배열을 초기화하는 생성자
    * @param[in] init_val 배열 요소를 이 값으로 모두 초기화한다.
    */
    SArray(const T& init_val);

    /*!
    * @note 복사 생성자(Copy Constructor)
    * @brief 다른 정적 배열의 값을 복사한 동일한 정적 배열로 초기화한다.
    * @param from 복사할 정적 배열
    */
    SArray(const SArray<T, ArraySize>& from);

    /*!
    * @note 복사 대입 생성자(Copy Assignment Operator)
    * @brief 
    * @param from 
    * @return 
    */
    SArray<T, ArraySize>& operator=(SArray<T, ArraySize>& from);

    /*!
    * @note 이동 생성자(Move Constructor)
    * @brief 
    * @param from 
    */
    SArray(SArray<T, ArrSize>&& from) noexcept;

    /*!
    * @note 이동 대입 생성자(Move Assignment Constructor)
    * @brief 
    * @param from 
    * @return 
    */
    SArray<T, ArraySize>& operator=(SArray<T, ArraySize>&& from);

    virtual ~SArray();

    /*!
     * @brief 아래 첨자 연산자([]) 오버로딩. 인덱스에 해당하는 배열 값에 접근한다. 왼쪽 값으로 반환한다.
     * @warning 인덱스가 유효한지는 검사하지 않는다.
     * @param index 접근할 배열 요소의 인덱스
     * @return 인덱스에 해당하는 배열 요소에 대한 왼쪽 값
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


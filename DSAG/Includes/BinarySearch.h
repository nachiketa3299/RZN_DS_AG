/// @file BinarySearch.h
/// @author RZN

/// 이진 탐색(Binary Search) 구현하기 - 표준 라이브러리 사용하여 구현
/// 근데 웃긴점 - 이미 표준에는 `binary_search` 가 존재함. ㅋㅋ

#ifndef _BINARY_SEARCH_H
#define _BINARY_SEARCH_H

/// @short 이진 탐색 함수
/// @note 탐색할 범위는 *미리* 정렬되어 있어야 한다.
/// @param[in] begin 탐색할 정렬된 범위의 시작 반복자
/// @param[in] end 탐색할 정렬된 범위의 끝 반복자
/// @param[in] val 탐색할 값
/// @param[in] compare 비교 함수
/// @return true면 탐색할 값이 범위에 하나 이상 존재함. false면 탐색할 값이 범위에 존재하지 않음.
template <typename FwdIt, typename DataType, class Compare>
bool binary_search(FwdIt begin, FwdIt end, const DataType& val, Compare compare)
{
#include <vector>
    std::vector<int>::iterator vec;
    return true;
}

#endif // !_BINARY_SEARCH_H
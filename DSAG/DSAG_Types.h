/// @file DSAGTypes.h
/// @author RZN
/// @short 반복되서 사용되는 타입과 매크로에 대한 정의

#ifndef _DSAG_TYPES_H
#define _DSAG_TYPES_H

#include <cstddef>

typedef std::size_t IndexType;
typedef std::size_t SizeType;
typedef int         DataType;
typedef int         WeightType;

#define ZERO_INDEX 0
#define ZERO_SIZE 0
#define INIT_CAPACITY 0
#define OVERFLOW_MULTIPLIER 2

#endif // !_DSAG_TYPES_H

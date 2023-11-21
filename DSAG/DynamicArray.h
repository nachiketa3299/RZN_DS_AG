#ifndef DSAG_DYNAMIC_ARRAY
#define DSAG_DYNAMIC_ARRAY

#include "Types.h"
#include "Array.h"

DSAG_BEGIN

template <typename T>
class IDynamicArray abstract
{
};

template <typename T>
class DynamicArray:
    public Array<T>,
    public IDynamicArray<T>
{
};

DSAG_END

#endif // !DSAG_DYNAMIC_ARRAY

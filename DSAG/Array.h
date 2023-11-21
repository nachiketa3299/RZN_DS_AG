#ifndef DSAG_ARRAY_H
#define DSAG_ARRAY_H

#include "Types.h"
#include "Sequence.h"

DSAG_BEGIN

template <typename T>
class IArray abstract
{
};

template <typename T>
class Array abstract:
    public IArray<T>,
    public Sequence<T>
{
};


DSAG_END


#endif // !DSAG_ARRAY_H

#ifndef DSAG_SEQUENCE_H
#define DSAG_SEQUENCE_H

#include "Types.h"
#include "Container.h"

DSAG_BEGIN

template <typename T>
class ISequence abstract
{
};

template <typename T>
class Sequence abstract:
    public ISequence<T>,
    public Container<T>
{
};


DSAG_END



#endif // !DSAG_SEQUENCE_H

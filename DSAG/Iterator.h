#ifndef _DSAG_ITERATOR_H
#define _DSAG_ITERATOR_H

#include "CoreDefinition.h"

_DSAG_BEGIN

template <typename Container>
class InputIterator
{
};

template <typename Container>
class OutputIterator
{
};

template <typename Container>
class ForwardIterator:
    public InputIterator<Container>,
    public OutputIterator<Container>
{
};

template <typename Container>
class BidirectionalIterator:
    public ForwardIterator<Container>
{
};

template <typename Container>
class RandomAccessIterator:
    public BidirectionalIterator<Container>
{
};

_DSAG_END

#endif // !_DSAG_ITERATOR_H

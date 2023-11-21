/*!
* @file Container.h
* @date 2023-11-10
*/

#ifndef DSAG_CONTAINER_H
#define DSAG_CONTAINER_H

#include "Types.h"

DSAG_BEGIN

template <typename T>

class IContainer abstract
{
public:
    virtual DSAG::SizeType GetSize() const abstract;
};

template <typename T>
class Container abstract:
    public IContainer<T>
{
public:
    DSAG::SizeType GetSize() const override NO_IMPLEMENTATION
private:
    T* data_;
};

DSAG_END

#endif // !DSAG_CONTAINER_H

/// @file Iterator_Interface.h
/// @author RZN

#ifndef _ITERATOR_INTERFACE_H
#define _ITERATOR_INTERFACE_H

class IIterator abstract
{
public:
    virtual IIterator* begin() abstract;
    virtual IIterator* end() abstract;
};

#endif // !_ITERATOR_INTERFACE_H



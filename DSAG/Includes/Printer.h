/// @file Printer.h
/// @date 2023-11-24


#ifndef DSAG_PRINTER_H
#define DSAG_PRINTER_H

#include "CoreDefinition.h"
#include "StaticArray.h"

#include <iostream>

_DSAG_BEGIN


template<typename Container>
void Print(const Container& container)
{
    return;
}

template<typename T, std::size_t Size>
void Print(const StaticArray<T, Size>& arr)
{
    std::cout << "[ ";
    for (std::size_t i = 0; i < Size; ++i)
        std::cout << arr[i] << (i == Size - 1 ? " ]\n" : ", ");
    return;
}


_DSAG_END


#endif // !DSAG_PRINTER_H

#include "StaticArray.h"
#include "Printer.h"

#include <iostream>

using namespace DSAG;

int main(void)
{
    StaticArray<int, 3> arr1(3);
    StaticArray<int, 3> arr2;
    arr1 = arr2;
    ::Print(arr1);
    StaticArray<int, 3> arr3(std::move(arr2));
    Print(arr3);
    std::cout << "Arr2:";
    Print(arr2);

}

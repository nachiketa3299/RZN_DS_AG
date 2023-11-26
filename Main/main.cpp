#include "StaticArray.h"
#include "Printer.h"

#include <iostream>
#include <vector>

using namespace DSAG;

int main(void)
{
    StaticArray<int, 3> arr1(3);
    StaticArray<int, 3>::Iterator iterator = arr1.Begin();


    for (auto it = arr1.Begin(); it != arr1.End(); ++it)
    {
        std::cout << *it << " ";
    }

}

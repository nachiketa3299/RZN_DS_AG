#include <StaticArray.h>
#include <DynamicArray.h>

#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    RStaticArray<int, 4> arr(5);

    arr.size();
    arr.print_ds();

    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] += (int)i + 1; 

    arr.print_ds();

    RDynamicArray<int> vec(8, 10);
    vec.print_ds();
    for (size_t i = 0; i < vec.size(); ++i)
        vec[i] += (int)i + 1;
    vec.print_ds();

	return 0;
}

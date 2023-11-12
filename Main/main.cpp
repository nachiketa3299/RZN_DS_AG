#include <StaticArray.hpp>
#include <DynamicArray.hpp>

#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    RDynamicArray<int> vec(1, 1);
    RStaticArray<int, 10> arr;
    arr.print_ds();
    if (!arr.empty())  cout << " Not Empty ! ";
	return 0;
}

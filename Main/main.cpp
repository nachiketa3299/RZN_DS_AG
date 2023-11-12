#include <StaticArray.hpp>
#include <DynamicArray.hpp>

#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    RArray::Dynamic<int> vec(1, 1);
    RArray::Static<int, 10> arr;

    arr.print_ds();

    if (!arr.empty())  cout << " Not Empty ! ";
	return 0;
}

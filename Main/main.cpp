#include <StaticArray.h>

#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    RStaticArray<int, 10> arr(10);
    arr[9] = 100;

    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ' ';
    }

	return 0;
}

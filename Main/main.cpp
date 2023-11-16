#include "BinarySearch.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Test
{
    Test(int val):val(val) {};
    int val;
    bool operator<(const Test& ref) { return this->val < ref.val; };
};


int main(void)
{
    vector<Test> vec = { Test(10), Test(8), Test(5), Test(7), Test(3) };
    sort(vec.begin(), vec.end());
    auto comp = [](const Test& a, const Test& b) { return a.val < b.val; };
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << i + 1 << ": " << (BinarySearch(vec.begin(), vec.end(), i + 1, comp) ? "true" : "false") << '\n';
    }
	return 0;
}

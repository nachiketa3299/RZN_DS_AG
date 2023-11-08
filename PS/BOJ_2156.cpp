/*!
* **백준 2156(S1, 포도주 시식)**
* 
* 포도주 시식에는 두 가지 규칙이 있다.
* - (1) 잔을 선택하면 그 잔은 다 비워야한다. 비운 잔은 원래 위치에 놓는다.
* - (2) 연속으로 3잔을 모두 마실 수는 없다.
* 
* 1 부터 n 까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있다. 그리고 각 잔에 들어있는 포도주의 양은 다르며, 양은 주어진다. 가장 많은 양의 포도주를 먹으려면?
* 
* 예를 들어 6개의 포도주 잔이 있고, [6, 10, 13, 9, 8, 1] 만큼 포도주가 들어 있을때, 0->1->3->4 를 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n; ///< [1, 1e4]
    vector<int> Wines(n);
    for (int& Wine : Wines)
        cin >> Wine; ///< [0, 1e3]



    return 0;
}
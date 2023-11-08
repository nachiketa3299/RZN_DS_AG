/*!
* 카드 구매하기(S1)
* @date 2023-10-30T23:25, 2023-10-31T00:23
*/

/*!
* 카드에는 8종이 있다
* 카드는 카드팩 형태로만 구매가 가능하다.
* *카드팩*은 카드 1개가 포함된 카드팩, 카드 2개가 포함된 카드팩, ... 카드 `N` 개가 포함된 카드팩까지 총 N 가지 종류가 존재한다.
* 
* 민규는 카드가 적게 들어있어도 가격이 비싸면 좋은 카드가 들어있을 거라는 미신을 믿는다.
* 따라서 돈을 최대한 많이 지불하여, 카드 `N`개를 구매하려고 한다. 카드 `i` 개가 포함된 카드팩의 가격은 `P_i`원이다.
* 
* 예를 들어, 카드팩이 총 4가지 종류가 있고, `P` = [1, 5, 6, 7]인 경우에 민규가 카드 4개를 갖기 위해 지불해야 하는 금액의 최대값은 5원을 2번 지불하는 10원이다.
* 
* 카드 팩의 가격이 주어졌을 때, `N`개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최댓값을 구하는 프로그램을 작성한다. (`N` 개보다 많은 갯수를 산 후 나머지를 버려 `N`개로 만드는 것은 불가능하다.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*!
* 그러니까 i개 카드 최대 구매하려면 (i개 카드 최대 구매가격을 K[i]라고 부르기)
* i- 1    번째까지 최대 구매하고 1  개 최대 구매하기 == K[i- 1   ] + K[ 1   ]
* i- 2    번째까지 최대 구매하고 2  개 최대 구매하기 == K[i- 2   ] + K[ 2   ]
* i- 3    번째까지 최대 구매하고 3  개 최대 구매하기 == K[i- 3   ] + K[ 3   ]
* i-(i-1) 번째까지 최대 구매하고 i-1개 최대 구매하기 == K[i-(i-1)] + K[(i-1)]
* 위 i-1 가지 경우의 값 중 최대임
* K 를 메모이제이션 하면 된다. (사실 절반만 해도 되는데 복잡도엔 거의 영향 없으므로 걍 함)
* 
* 예를들어 카드 4개 최대 구매하려면 K[4]이고 얘는
* max(P[4], K[1] + K[3], K[2] + K[2]) 라는거임.
*/
int main()
{
    int N; cin >> N; // N [1, 1e3]
    vector<int> P(N);
    for (int& P_i : P) cin >> P_i; ///< P_i [1, 1e4]
    vector<int> K(N); // K[i]는 i + 1개 카드를 구매하기 위한 최대 금액

    for (size_t i = 0; i < N; ++i)
    {
        int cmax = P[i]; // 일단 N개 최대를 P[N]이라고 가정
        for (size_t j = 0; j < i; ++j)
        {
            int candid = K[j] + K[i - j - 1];
            if (cmax < candid) cmax = candid;
        }
        K[i] = cmax;
    }
   cout << K.back() << '\n';
}
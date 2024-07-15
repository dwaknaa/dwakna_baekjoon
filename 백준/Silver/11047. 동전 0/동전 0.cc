#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N = 0;
    int K = 0;
    cin >> N >> K;

    set<int, greater<>> coinSet;
    for(int i=0; i<N; i++)
    {
        int coin = 0;
        cin >> coin;
        coinSet.insert(coin);
    }

    // 필요한 동전 개수
    int answer = 0;
    for(auto iter=coinSet.begin(); iter!=coinSet.end(); iter++)
    {
        if(K == 0) break;
        int coin = *iter;

        // 동전 금액이 현재 남은 금액보다 크면 다음 동전으로 넘어간다.
        if(coin > K) continue;

        answer += (K / coin);
        K %= coin;
    }

    cout << answer << endl;   
}
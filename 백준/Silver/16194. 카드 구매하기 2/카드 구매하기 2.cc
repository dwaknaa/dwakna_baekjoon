#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> dp;

int main()
{
    cin.tie(0);
    
    cin >> N;

    dp.assign(N+1, 0);

    int min = 0;
    for(int i=1; i<=N; i++)
    {
        cin >> min;

        for(int j=1; j<i; j++)
        {
            int temp = dp[j] + dp[i-j];
            if(min > temp) min = temp;
        }
        dp[i] = min;
    }

    cout << dp[N] << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int K, N;

void func()
{
    for(int i=1; i<=K; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(j==1) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
}

int main()
{
    cin.tie(0);

    int t = 0;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> K;
        cin >> N;

        dp.assign(K+1, vector<int>(N+1, 0));

        for(int j=1; j<=N; j++)
        {
            dp[0][j] = j;
        }

        func();

        cout << dp[K][N] << endl;

        dp.clear();
    }

    return 0;
}
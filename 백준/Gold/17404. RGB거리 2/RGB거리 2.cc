#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> vec;
vector<vector<int>> dp;


int main()
{
    cin.tie(0);

    cin >> N;

    vec.assign(N+1, vector<int>(3, 0));
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> vec[i][j];
        }
    }

    dp.assign(N+1, vector<int>(3, 10001));

    // 1. 첫번째 집 = R
    dp[1][0] = vec[1][0];
    for(int i=2; i<=N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + vec[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + vec[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + vec[i][2];
    }

    int rMin = min(dp[N][1], dp[N][2]);

    dp.clear();
    dp.assign(N+1, vector<int>(3, 10001));

    // 2. 첫번째 집 = G
    dp[1][1] = vec[1][1];
    for(int i=2; i<=N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + vec[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + vec[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + vec[i][2];
    }

    int gMin = min(dp[N][0], dp[N][2]);

    dp.clear();
    dp.assign(N+1, vector<int>(3, 10001));

    // 3. 첫번째 집 = B
    dp[1][2] = vec[1][2];
    for(int i=2; i<=N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + vec[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + vec[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + vec[i][2];
    }

    int bMin = min(dp[N][0], dp[N][1]);

    cout << min(min(rMin, gMin), bMin) << endl;

    return 0;
}
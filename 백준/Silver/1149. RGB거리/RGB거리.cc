#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> vec;
vector<vector<int>> dp;


int main()
{
    cin.tie(0);

    int n = 0;
    cin >> n;

    vec.assign(n+1, vector<int>(3, 0));
    dp.assign(n+1, vector<int>(3, 0));

    int r, g, b;
    for(int i=1; i<=n; i++)
    {
        cin >> r >> g >> b;
        vec[i][0] = r;
        vec[i][1] = g;
        vec[i][2] = b;
    }
    
    for(int i=1; i<=n; i++)
    {
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]) + vec[i][0];
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]) + vec[i][1];
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]) + vec[i][2];
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> dp;
vector<int> vec;

int main()
{
    cin.tie(0);
    
    cin >> N;

    vec.assign(N+1, 0);
    for(int i=1; i<=N; i++)
    {
        cin >> vec[i];
    }

    dp.assign(N+1, 0);
    dp[1] = 1;
    for(int i=2; i<=N; i++)
    {
        int min = 0;
        for(int j=1; j<i; j++)
        {
            if(vec[j]<vec[i] && dp[j]>min) min = dp[j];
        }

        dp[i] = min+1;
    }

    sort(dp.begin(), dp.end());

    cout << N - dp.back() << endl;

    return 0;
}
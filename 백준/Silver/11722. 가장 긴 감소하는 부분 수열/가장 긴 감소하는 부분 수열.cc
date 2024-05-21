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

    dp.assign(N+1, 1);
    for(int i=2; i<=N; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(vec[i] < vec[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    sort(dp.begin(), dp.end());
    
    cout << dp.back() << endl;

    return 0;
}
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
    int max = 0;
    for(int i=1; i<=N; i++)
    {
        int min = 0;
        for(int j=0; j<i; j++)
        {
            if(vec[j]<vec[i] && dp[j]>min) min = dp[j];
        }

        dp[i] = min+1;
        if(dp[i] > max) max = dp[i];
    }

    cout << max << endl;
    reverse(dp.begin(), dp.end());
    reverse(vec.begin(), vec.end());

    vector<int> answer;
    for(int i=0; i<N; i++)
    {
        if(dp[i]==max)
        {
            answer.push_back(vec[i]);
            max--;
            if(max==0) break;
        }
    }

    reverse(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}
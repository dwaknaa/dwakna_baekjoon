#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int N;

int main()
{
    cin.tie(0);

    cin >> N;

    vector<int> pay;
    pay.assign(N+1, 0);
    int num = 0;
    for(int i=1; i<=N; i++)
    {
        cin >> num;
        pay[i] = num;
    }

    dp.assign(N+1, 0);
    dp[1] = pay[1];

    for(int i=2; i<=N; i++)
    {
        int max = 0;
        for(int j=1; j<=i; j++)
        {
            if(max < dp[j] + pay[i-j]) max = dp[j] + pay[i-j];
        }
        if(pay[i] < max) dp[i] = max;
        else dp[i] = pay[i];
    }

    cout << dp.back() << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int dp(int target)
{
    vec[target] = vec[target-3] + vec[target-2] + vec[target-1];

    return vec[target];
}

int main()
{
    cin.tie(0);

    int t = 0;
    cin >> t;

    vec.assign(12, 0);
    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 4;

    for(int i=4; i<=11; i++)
    {
        dp(i);
    }

    int n = 0;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        cout << vec[n] << endl;
    }

    return 0;
}
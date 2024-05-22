#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
    cin.tie(0);
    
    string str = "";
    string str2 = "";

    cin >> str >> str2;

    string longStr = str.length() > str2.length() ? str : str2;
    string shortStr = str.length() <= str2.length() ? str : str2;

    vector<vector<int>> dp;
    dp.push_back(vector<int>(longStr.length()+1, 0));
    string lcsStr = "";

    for(int i=0; i<shortStr.length(); i++)
    {
        vector<int> vec;
        vec.push_back(0);

        for(int j=0; j<longStr.length(); j++)
        {
            if(shortStr[i]==longStr[j])
            {
                vec.push_back(dp[i][j]+1);
            }
            else
            {
                int num = vec.back() > dp[i][j+1] ? vec.back() : dp[i][j+1];
                vec.push_back(num);
            }
        }
        dp.push_back(vec);
    }

    sort(dp.back().begin(), dp.back().end());

    cout << dp.back().back() << endl;
    
    return 0;
}
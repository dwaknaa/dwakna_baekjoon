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

    vector<vector<int>> dp;
    dp.push_back(vector<int>(str2.length()+1, 0));

    for(int i=0; i<str.length(); i++)
    {
        vector<int> vec;
        vec.push_back(0);

        for(int j=0; j<str2.length(); j++)
        {
            if(str[i]==str2[j])
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

    int lcsLen = dp.back().back();
    cout << lcsLen << endl;

    if(lcsLen==0) return 0;
    
    string lcsStr = "";
    for(int i=dp.size()-1; i>=0; i--)
    {
        for(int j=dp[i].size()-1; j>=0; j--)
        {
            if(dp[i][j]==lcsLen && str[i]==str2[j])
            {
                lcsStr += str[i];
                lcsLen -= 1;
                break;
            }
        }
    }

    reverse(lcsStr.begin(), lcsStr.end());
    cout << lcsStr << endl;

    return 0;
}
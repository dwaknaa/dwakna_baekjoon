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

    vector<vector<int>> lcsVec;
    lcsVec.push_back(vector<int>(longStr.length()+1, 0));
    int maxCnt = 0;
    for(int i=0; i<shortStr.length(); i++)
    {
        vector<int> vec;
        vec.push_back(0);

        for(int j=0; j<longStr.length(); j++)
        {
            if(shortStr[i]==longStr[j])
            {
                vec.push_back(lcsVec[i][j]+1);
                maxCnt = max(maxCnt, vec.back());
            }
            else
            {
                int num = vec.back() > lcsVec[i][j+1] ? vec.back() : lcsVec[i][j+1];
                vec.push_back(num);
            }

        }
        lcsVec.push_back(vec);
    }

    cout << maxCnt << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> aVec;
    long long num = 0;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        aVec.push_back(num);
    }

    sort(aVec.begin(), aVec.end());

    int m = 0;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> num;
        printf("%d\n", binary_search(aVec.begin(), aVec.end(), num));
    }

    return 0;
}
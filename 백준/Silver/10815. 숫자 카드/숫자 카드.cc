#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    
    int n, m;
    cin >> n;

    int num = 0;
    vector<int> vec;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    
    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> num;
        printf("%d ", binary_search(vec.begin(), vec.end(), num));
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;
vector<bool> visited;
int cnt;

void dfs(int index)
{
    visited[index] = true;
    cnt++;

    if(index+vec[index]<n && !visited[index+vec[index]]) dfs(index+vec[index]);

    if(index-vec[index]>=0 && !visited[index-vec[index]]) dfs(index-vec[index]);
}

int main()
{
    cin >> n;

    int num;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    int s = 0;
    cin >> s;

    visited.assign(n, false);
    cnt = 0;
    dfs(s-1);

    cout << cnt << endl;

    return 0;
}
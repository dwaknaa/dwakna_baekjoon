#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<int> upVect[101];
vector<int> downVect[101];

int cnt;

void dfs(vector<int> v[], int vertex)
{
    visited[vertex] = true;
    for(int i=0; i<v[vertex].size(); i++)
    {
        int next = v[vertex][i];
        if(!visited[next])
        {
            cnt++;
            dfs(v, next);
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;

    int m = 0;
    cin >> m;

    int u, v;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        upVect[u].push_back(v);
        downVect[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cnt = 0;
        visited.assign(n+1, false);
        dfs(upVect, i);
        visited.assign(n+1, false);
        dfs(downVect, i);
        
        cout << n-cnt-1 << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> vect[1001];


void dfs(int vertex)
{
    visited[vertex] = true;

    for(int i=0; i<vect[vertex].size(); i++)
    {
        int index = vect[vertex][i];
        if(!visited[index])
        {
            dfs(index);
        }
    }    
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int u = 0;
    int v = 0;
    
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u);
    }

    int cnt = 0;
    visited.assign(n+1, false);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
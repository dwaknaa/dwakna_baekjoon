#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;

vector<bool> dfsVisit;
vector<int> dfsVec;

vector<bool> bfsVisit;
vector<int> bfsVec;

void dfs(int index)
{
    dfsVisit[index] = true;

    dfsVec.push_back(index);

    auto v = graph[index];
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    {
        int next = v[i];
        if(!dfsVisit[next])
        {
            dfs(next);
        }
    }
}

void bfs(int node)
{
    bfsVisit[node] = true;
    queue<int> que;
    que.push(node);

    while(!que.empty())
    {
        int n = que.front();
        que.pop();
        bfsVec.push_back(n);

        auto v = graph[n];
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++)
        {
            int next = v[i];
            if(!bfsVisit[next])
            {
                bfsVisit[next] = true;
                que.push(next);
            }
        }
    }
}

int main()
{
    int N, M, V;

    cin >> N >> M >> V;

    graph.assign(N+1, vector<int>(0, 0));
    dfsVisit.assign(N+1, false);
    bfsVisit.assign(N+1, false);

    int u, v;
    for(int i=0; i<M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(V);
    bfs(V);

    for(int i=0; i<dfsVec.size(); i++)
    {
        cout << dfsVec[i] << " ";
    }
    cout << endl;

    for(int i=0; i<bfsVec.size(); i++)
    {
        cout << bfsVec[i] << " ";
    }
    cout << endl;

    return 0;
}
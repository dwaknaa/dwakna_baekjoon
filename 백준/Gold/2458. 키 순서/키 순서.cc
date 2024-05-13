#include <iostream>
#include <vector>
using namespace std;

vector<int> upVect[501];
vector<int> downVect[501];
vector<bool> visited;
int cnt = 0;

void dfs(vector<int> vec[], int vertex)
{
    visited[vertex] = true;
    for(int i=0; i<vec[vertex].size(); i++)
    {
        int next = vec[vertex][i];
        if(!visited[next])
        {
            cnt++;
            dfs(vec, next);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    int a, b;
    for(int i=0; i<M; i++)
    {
        cin >> a >> b;
        upVect[b].push_back(a);
        downVect[a].push_back(b);
    }

    int answer = 0;
    for(int i=1; i<=N; i++)
    {
        cnt = 0;
        visited.assign(N+1, false);
        dfs(downVect, i);
        visited.assign(N+1, false);
        dfs(upVect, i);

        if(cnt == N-1) answer++;
    }

    cout << answer << endl;

    return 0;
}
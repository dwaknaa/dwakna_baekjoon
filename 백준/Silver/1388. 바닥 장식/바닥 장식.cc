#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> visited[51];
vector<string> vect[51];

int N, M;
int answer;

void dfs(int n, int m)
{
    visited[n][m] = true;
    answer++;

    if(vect[n][m] == "-")
    {
        for(int i=m+1; i<M; i++)
        {
            if(!visited[n][i] && vect[n][i] == "-")
            {
                visited[n][i] = true;
            }
            else
            {
                return;
            }
        }
    }
    else if(vect[n][m] == "|")
    {
        for(int i=n+1; i<N; i++)
        {
            if(!visited[i][m] && vect[i][m] == "|")
            {
                visited[i][m] = true;
            }
            else
            {
                return;
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        string str = "";
        cin >> str;
        if(str.length()!=M) continue;

        for(int j=0; j<M; j++)
        {
            vect[i].push_back(str.substr(j, 1));
            visited[i].push_back(false);
        }
    }

    answer = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);
            }
        }
    }

    cout << answer << endl;

    return 0;
}
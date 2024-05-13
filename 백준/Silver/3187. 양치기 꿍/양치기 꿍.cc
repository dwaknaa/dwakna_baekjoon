#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> visited[251];
vector<string> vect[251];

int R, C;
int answer;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

int sheep, wolf;

void dfs(int n, int m)
{
    visited[n][m] = true;

    if(vect[n][m] == "v") wolf++;
    else if(vect[n][m] == "k") sheep++;

    for(int i=0; i<4; i++)
    {
        int nx = m+dx[i];
        int ny = n+dy[i];

        if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;

        if(!visited[ny][nx] && vect[ny][nx]!="#")
        {
            dfs(ny, nx);
        }
    }

    return;
}

int main()
{
    cin >> R >> C;

    for(int i=0; i<R; i++)
    {
        string str = "";
        cin >> str;
        if(str.length()!=C) continue;

        for(int j=0; j<C; j++)
        {
            vect[i].push_back(str.substr(j, 1));
            visited[i].push_back(false);
        }
    }

    int allSheep = 0;
    int allWolf = 0;

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(!visited[i][j] && vect[i][j]!="#")
            {
                sheep = 0;
                wolf = 0;

                dfs(i, j);
                if(sheep > wolf) allSheep += sheep;
                else allWolf += wolf;
            }
        }
    }

    cout << allSheep << " " << allWolf << endl;

    return 0;
}
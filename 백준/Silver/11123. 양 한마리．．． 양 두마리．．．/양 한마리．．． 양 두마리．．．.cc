#include <iostream>
#include <cstring>
using namespace std;

string vect[100][100];
bool visited[100][100];

int w, h;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

void dfs(int y, int x)
{
    visited[y][x] = true;

    for(int i=0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
    
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

        if(!visited[ny][nx] && vect[ny][nx]=="#")
        {
            dfs(ny, nx);
        }
    }

    return;
}

int main()
{
    int t = 0;
    cin >> t;

    for(int k=0; k<t; k++)
    {
        memset(visited, false, sizeof(visited));
        int cnt = 0;

        cin >> h >> w;

        for(int i=0; i<h; i++)
        {
            string str = "";
            cin >> str;
            for(int j=0; j<w; j++)
            {
                vect[i][j] = str.substr(j, 1);
                visited[i][j] = false;
            }
        }

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(!visited[i][j] && vect[i][j]=="#")
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int vect[51][51];
bool visited[51][51];

int w, h;

int dx[] = {0, 0, -1, +1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

void dfs(int y, int x)
{
    visited[y][x] = true;

    for(int i=0; i<8; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
    
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

        if(!visited[ny][nx] && vect[ny][nx])
        {
            dfs(ny, nx);
        }
    }

    return;
}

int main()
{
    vector<int> answer;

    while(1)
    {
        memset(visited, false, sizeof(visited));
        int cnt = 0;

        cin >> w >> h;
        if(w==0 && h==0) break;

        int num;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin >> num;
                vect[i][j] = num;
                visited[i][j] = false;
            }
        }

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(!visited[i][j] && vect[i][j])
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
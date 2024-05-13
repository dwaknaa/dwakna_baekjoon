#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> vect[251];
vector<bool> visited[251];

int N, M;

int dx[] = {0, 0, -1, +1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

void dfs(int y, int x)
{
    visited[y][x] = true;

    for(int i=0; i<8; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
    
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;

        if(!visited[ny][nx] && vect[ny][nx])
        {
            dfs(ny, nx);
        }
    }

    return;
}

int main()
{
    cin >> M >> N;
    
    int num;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> num;
            vect[i].push_back(num);
            visited[i].push_back(false);
        }
    }

    int cnt = 0;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!visited[i][j] && vect[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;

    return 0;
}
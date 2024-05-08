#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<bool>> visited;
vector<vector<string>> painting;

// 상, 하, 좌, 우 탐색
int dx[] = { 1,-1,0,0 }; 
int dy[] = { 0,0,1,-1 };

void dfs(int nowx, int nowy)
{
	if (visited[nowx][nowy]) return;  

	visited[nowx][nowy] = true; // 좌표 방문 처리

	for (int i = 0; i < 4; i++) // 상하좌우
	{
		int X = dx[i] + nowx; 
		int Y = dy[i] + nowy;
		
        if(X < 0 || X >= painting.size()
        || Y < 0 || Y >= painting.size()) continue;

        if ((painting[nowx][nowy] == painting[X][Y]) && !visited[X][Y])
        {
            dfs(X, Y);
        }
	}
}

int main() 
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        std::string str = "";
        cin >> str;

        if(str.length()==n)
        {
            vector<string> vec;
            for(int j=0; j<n; j++)
            {
                vec.push_back(str.substr(j, 1));
            }

            painting.push_back(vec);
        }
    }

    int areaCnt = 0;
    vector<bool> vec;
    vec.assign(n, false);
    visited.assign(n, vec);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);
                areaCnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
	{
        replace(painting[i].begin(), painting[i].end(), "G", "R");
	}

    int rgAreaCnt = 0;
    visited.clear();
    visited.assign(n, vec);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);
                rgAreaCnt++;
            }
        }
    }

    cout << areaCnt << " " << rgAreaCnt << endl;

    return 0;
}
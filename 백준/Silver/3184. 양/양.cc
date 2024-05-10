#include <iostream>
#include <vector>

using namespace std;


int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

vector<vector<string>> area;
vector<vector<bool>> visited;

int sheep;
int wolf;

void dfs(int r, int c)
{
    visited[r][c] = true;

    if(area[r][c] == "o") sheep++;
    else if(area[r][c] == "v") wolf++;

    for(int i=0; i<4; i++)
    {
        int nextX = c+dx[i];
        int nextY = r+dy[i];

        if(nextX < 0 || nextX >= area[r].size()
        || nextY < 0 || nextY >= area.size()) continue;

        if(area[nextY][nextX] == "#")
        {
            visited[nextY][nextX] = true;
            continue;
        }

        if(!visited[nextY][nextX])
        {
            dfs(nextY, nextX);
        }
    }
}

int main()
{
    int r,c;
    cin >> r >> c;

    for(int i=0; i<r; i++)
    {
        string str = "";
        cin >> str;
    
        if(str.length() != c) continue;

        vector<string> vec;
        vector<bool> visitVec(c, false);
        for(int j=0; j<c; j++)
        {
            vec.push_back(str.substr(j, 1));
        }
        area.push_back(vec);
        visited.push_back(visitVec);
    }

    sheep = 0;
    wolf = 0;

    int allSheep = 0;
    int allWolf = 0;
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);

                if(sheep > wolf) allSheep += sheep;
                else allWolf += wolf;

                sheep = 0;
                wolf = 0;
            }
        }
    }

    cout << allSheep << " " << allWolf << endl;
    
    return 0;
}
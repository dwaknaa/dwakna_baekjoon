#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> vect[6];
set<string> s;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

void dfs(int y, int x, string str)
{
    if(str.length()==6)
    {
        s.insert(str);
        return;
    }

    for(int i=0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;

        dfs(ny, nx, str+to_string(vect[ny][nx]));
    }
}

int main()
{
    int num;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin >> num;
            vect[i].push_back(num);
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            dfs(i, j, to_string(vect[i][j]));
        }
    }

    cout << s.size() << endl;

    return 0;
}
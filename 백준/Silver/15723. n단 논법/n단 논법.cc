#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
map<string, string> query;
vector<bool> visited;

bool dfs(string a, string b)
{
    if(query.find(a) == query.end()) return false;
    if(query[a] == b) return true;

    int k = distance(query.begin(), query.find(a));
    visited[k] = true;

    if(query.find(query[a]) == query.end()) return false;

    int next = distance(query.begin(), query.find(query[a]));
    if(!visited[next])
    {
        return dfs(query[a], b);
    }
}

int main()
{
    cin >> n;

    string a, is ,b;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        cin >> is;
        cin >> b;

        query[a] = b;
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        visited.assign(n, false);
        cin >> a;
        cin >> is;
        cin >> b;

        bool ret = dfs(a, b);
        if(ret) cout << "T" << endl;
        else cout << "F" << endl;
    }

    return 0;
}
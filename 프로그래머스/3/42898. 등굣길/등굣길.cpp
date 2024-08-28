#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;

    vector<int> coor(m, -1);
    vector<vector<int>> map(n, coor);

	// 웅덩이
	for(auto iter=puddles.begin(); iter!=puddles.end(); iter++)
	{
		map[iter->at(1)-1][iter->at(0)-1] = 0;
	}

	// x축 첫줄 초기화
	bool xPuddle = false;
	for(int i=1; i<m; i++)
	{
		if(!xPuddle)
		{
			xPuddle = map[0][i]==0 ? true : false;
			if(xPuddle) continue;

			map[0][i] = 1;
		}
		else
		{
			map[0][i] = 0;
		}
	}

	// y축 첫줄 초기화
	bool yPuddle = false;
	for(int j=1; j<n; j++)
	{
		if(!yPuddle)
		{
			yPuddle = map[j][0]==0 ? true : false;
			if(yPuddle) continue;

			map[j][0] = 1;
		}
		else
		{
			map[j][0] = 0;
		}
	}

	// 나머지 경로 계산
	for(int j=1; j<n; j++)
    {
   	 	for(int i=1; i<m; i++)
        {
			if(j==n-1 && i==m-1) break;

			// 웅덩이
            if(map[j][i]==0)
            {
                continue;
            }

			// 정상적인 경로
			map[j][i] = (map[j-1][i] + map[j][i-1]) % 1000000007;
        }
    }
    
	answer = (map[n-2][m-1] + map[n-1][m-2]) % 1000000007;

    return answer;
}
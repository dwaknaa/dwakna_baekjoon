#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;

    // 각 사람이 최소 시간을 기다리려면
    // 본인 앞에 본인보다 걸리는 시간이 긴 사람이 있으면 안됨
    // 그렇기 때문에 multiset으로 걸리는 시간 정렬
    multiset<int> timeSet;
    for(int i=0; i<N; i++)
    {
        int time = 0;
        cin >> time;
        timeSet.insert(time);
    }    

    // (본인 앞의 누적합 + 본인 소요시간) 각각 계산
    int sum = 0;
    int answer = 0;
    for(auto iter=timeSet.begin(); iter!=timeSet.end(); iter++)
    {
        sum += *iter;
        answer += sum;
    }

    cout << answer << endl;
}
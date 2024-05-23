#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int K = 0;
    cin >> K;

    int num = 0;
    stack<int> st;
    for(int i=0; i<K; i++)
    {
        cin >> num;

        if(num!=0) st.push(num);
        else st.pop();
    }

    int sum = 0;
    while(!st.empty())
    {
        sum += st.top();
        st.pop();
    }

    cout << sum << endl;

    return 0;
}
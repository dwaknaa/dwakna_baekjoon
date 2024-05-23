#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

bool isPrime(int num)
{
    if(num==2) return true;

    if(num<=1 || num%2==0) return false;

    for(int i=3; i<=sqrt(num); i+=2)
    {
        if(num%i==0) return false;
    }

    return true;
}

int main()
{
    int M = 0;
    int N = 0;
    cin >> M >> N;

    int sum = 0;
    int min = INT_MAX;
    for(int i=M; i<=N; i++)
    {
        if(isPrime(i)) 
        {
            sum += i;
            if(i < min) min = i;
        }
    }

    if(sum > 0)
    {
        cout << sum << endl;
        cout << min << endl;
    }
    else
    {
        cout << "-1" << endl;
    } 

    return 0;
}
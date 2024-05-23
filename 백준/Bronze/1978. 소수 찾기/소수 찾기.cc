#include <iostream>
#include <cmath>
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
    int N = 0;
    cin >> N;

    int cnt = 0;
    int input = 0;
    for(int i=0; i<N; i++)
    {
        cin >> input;

        if(isPrime(input)) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
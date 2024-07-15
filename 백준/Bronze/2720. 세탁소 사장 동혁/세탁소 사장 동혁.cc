#include <iostream>

using namespace std;

// 센트로 변환 ( 1달러 = 100센트 )
const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

void printEachCoinCnt(int change)
{
    cout << change/quarter << " ";
    change %= quarter;

    cout << change/dime << " ";
    change %= dime;

    cout << change/nickel << " ";
    change %= nickel;

    cout << change/penny << endl;
}

int main()
{
    int N = 0;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int change = 0;
        cin >> change;

        printEachCoinCnt(change);
    }
}
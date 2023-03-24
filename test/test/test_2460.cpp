//
//  test_2460.cpp
//  test
//
//  Created by user on 2023/03/24.
//

#include <iostream>
#include <string>

int main()
{
    int input[10] = {0, };
    int output[10] = {0, };
    
    for(int i = 0; i < 10; i++)
    {
        std::cin >> output[i] >> input[i];
    }
    
    // 조건 2. 출발역에서 내린 사람 수와 종착역에서 탄 사람 수는 0이다
    if(input[9] != 0 || output[0] != 0)
    {
        return 0;
    }
    
    int max = 0;
    int sum = 0;
    // 조건 1. 기차는 역 번호 순서대로 운행한다
    for(int i = 0; i < 10; i++)
    {
        // 조건 3. 각 역에서 현재 기차에 있는 사람보다 더 많은 사람이 내리는 경우는 없다
        // 조건 4. 기차의 정원은 최대 10,000명이고, 정원을 초과하여 타는 경우는 없다
        if(i > 0 && (output[i] > sum || sum > 10000))
        {
            return 0;
        }
        sum -= output[i];
        sum += input[i];
        
        if(max < sum)
        {
            max = sum;
        }
    }
    
    std::cout << max << std::endl;
    
    return 0;
}

//
//  test_2577.cpp
//  test
//
//  Created by user on 2023/03/24.
//

#include <iostream>
#include <string>
#include <string.h>

int main()
{
    int a, b, c;
    
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    
    // 조건 1. A, B, C는 모두 100보다 크거나 같고, 1,000보다 작은 자연수이다
    if(a < 100 || b < 100 || c < 100 ||
       a > 1000 || b > 1000 || c > 1000)
    {
        return 0;
    }
    
    std::string number = std::to_string(a*b*c); // 세 개의 숫자를 곱한 값
    int count[10] = {0, }; // 0~9까지 몇번 쓰였는지 저장할 배열

    for(int i = 0; i < 10; i++)
    {
        // 곱셈 결과의 각 자리수마다 0~9가 존재하는지 확인
        for(int j = 0; j < number.length(); j++)
        {
            std::string num;
            num += number[j];
            if(num == std::to_string(i))
            {
                // 존재하면 해당 숫자의 count 1 증가
                count[i] += 1;
            }
        }
        
        std::cout << count[i] << std::endl;
    }
    
    return 0;
}

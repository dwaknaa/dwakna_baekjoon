//
//  test_2592.cpp
//  test
//
//  Created by user on 2023/03/26.
//

#include <iostream>
#include <map>


int main()
{
    std::map<int, int> numberInfo; // <입력받은 숫자, 입력 횟수>를 저장하기 위한 map
    int maxCntNumber = 0; // 최다 입력된 숫자
    int maxCnt = 0; // 최다 입력된 숫자의 입력수
    int sum = 0; // 입력받은 숫자의 총합
    
    for(int i = 0; i < 10; i++)
    {
        int number;
        
        std::cin >> number;
        
        // 조건. 1000 이하이고 10의 배수
        if(number > 1000 || (number % 10 != 0))
        {
            return 0;
        }
        
        if(numberInfo.find(number) != numberInfo.end()) // 이미 입력됐던 숫자이면
        {
            numberInfo[number] += 1; // 입력 횟수를 +1 해준다
        }
        else // 입력받지 않았던 숫자이면
        {
            numberInfo.insert({number, 1}); // map에 넣어준다
        }
        
        // 최다 입력된 수의 조건을 만족하는지 확인
        if(numberInfo[number] > maxCnt)
        {
            maxCnt = numberInfo[number];
            maxCntNumber = number;
        }
        
        sum += number;
    }
    
    std::cout << sum/10 << std::endl;
    std::cout << maxCntNumber << std::endl;
    
    return 0;
}

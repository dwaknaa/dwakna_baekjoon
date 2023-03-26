//
//  test_2711.cpp
//  test
//
//  Created by user on 2023/03/27.
//

#include <iostream>
#include <string>
#include <cctype> // for 'isupper'


int main()
{
    int testCnt;
    
    std::cin >> testCnt;
    
    // 조건 1. 테스트 케이스의 개수 T(1<=T<=1,000)
    if(testCnt >= 1 && testCnt <= 1000)
    {
        for(int i = 0; i < testCnt; i++)
        {
            int index;
            std::string str;
            
            std::cin >> index >> str;
                
            // 조건 2. 문자열의 길이는 80을 넘지 않고, 오타를 낸 위치는 문자열 길이보다 작거나 같다
            if(str.length() > 80 || index > str.length())
            {

                return 0;
            }
            
            // 조건 3. 문자열은 대문자로만 이루어져 있다.
            for(int j = 0; j < str.length(); j++)
            {
                if(isupper(str[j]) == 0) // 문자열의 모든 문자가 대문자인지 확인
                {
                    return 0;
                }
            }
            
            // 문자열의 첫 글자부터 지워야 하는 글자 전까지 자른 것 + 지워야 하는 글자 이후부터 문자열 끝
            std::cout << str.substr(0, index - 1)  << str.substr(index) << std::endl;
        }
    }
    
    return 0;
}

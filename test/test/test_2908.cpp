//
//  test_2908.cpp
//  test
//
//  Created by user on 2023/03/24.
//

#include <iostream>
#include <string>


std::string reverseString(std::string str)
{
    std::string reversedStr = "";
    
    for(int i = 1; i <= str.length(); i++)
    {
        reversedStr += str[str.length() - i];
    }
 
    return reversedStr;
}


int main()
{
    std::string a, b;
    
    std::cin >> a >> b;
    
    // 조건 1. 입력받은 숫자의 길이가 세자리수를 넘는지 확인
    if(a.length() > 3 || b.length() > 3)
    {
        return 0;
    }
    
    // 조건 2. 입력받은 숫자에 '0'이 포함되어 있는지 확인
    if(a.find("0") != std::string::npos ||
       b.find("0") != std::string::npos)
    {
        return 0;
    }
    
    // 조건 3. 두 수가 같은 수인지 확인
    if(a == b)
    {
        return 0;
    }
    
    std::string reversedA = reverseString(a);
    std::string reversedB = reverseString(b);
    
    if(!reversedA.empty() && !reversedB.empty())
    {
        try
        {
            int bigger = std::stoi(reversedA) > std::stoi(reversedB) ?
            std::stoi(reversedA) : std::stoi(reversedB);
            
            std::cout << bigger << std::endl;
        }
        catch (...)
        {
            return 0;
        }
    }
    
    return 0;
}

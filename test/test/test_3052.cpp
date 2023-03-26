//
//  test_3052.cpp
//  test
//
//  Created by user on 2023/03/27.
//

#include <iostream>
#include <set>


int main()
{
    std::set<int> number;
    
    for(int i = 0; i < 10; i++)
    {
        int num;
        std::cin >> num;
        
        // 조건. 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다
        if(num < 0 || num > 1000)
        {
            return 0;
        }
        
        number.insert(num%42);
    }
    
    std::cout << number.size() << std::endl;
    return 0;
}

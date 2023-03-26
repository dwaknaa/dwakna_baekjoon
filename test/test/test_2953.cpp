//
//  test_2953.cpp
//  test
//
//  Created by user on 2023/03/27.
//

#include <iostream>


int main()
{
    int winner, winnerScore = 0;
    
    for(int i = 0; i < 5; i++)
    {
        int score[4] = {0, };
        int sum = 0;
        
        std::cin >> score[0] >> score[1] >> score[2] >> score[3];
        
        // 조건. 점수는 1점부터 5점까지 있다
        for(int j = 0; j < 4; j++)
        {
            if(score[j] < 1 || score[j] > 5)
            {
                return 0;
            }
            
            sum += score[j];
        }
        
        if(sum > winnerScore)
        {
            winnerScore = sum;
            winner = i+1;
        }
    }
    
    std::cout << winner << " " << winnerScore << std::endl;
    return 0;
}

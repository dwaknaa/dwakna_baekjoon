//
//  test_3003.cpp
//  test
//
//  Created by user on 2023/03/24.
//

#include <iostream>


enum ChessCount
{
    KING = 1,
    QUEEN = 1,
    ROOK = 2,
    BISHOP = 2,
    KNIGHT = 2,
    PAWN = 8
};


int main()
{
    int king, queen, rook, bishop, knight, pawn;
    
    // 개수 입력
    std::cin >> king >> queen >> rook >> bishop >> knight >> pawn;
    
    if(king >= 0 && king <= 10 &&
       queen >= 0 && queen <= 10 &&
       rook >= 0 && rook <= 10 &&
       bishop >= 0 && bishop <= 10 &&
       knight >= 0 && knight <= 10 &&
       pawn >= 0 & pawn <= 10)
    {
        std::cout << static_cast<int>(ChessCount::KING)-king << " "
                    << static_cast<int>(ChessCount::QUEEN)-queen << " "
                    << static_cast<int>(ChessCount::ROOK)-rook << " "
                    << static_cast<int>(ChessCount::BISHOP)-bishop << " "
                    << static_cast<int>(ChessCount::KNIGHT)-knight << " "
                    << static_cast<int>(ChessCount::PAWN)-pawn;
    }
    
    return 0;
}

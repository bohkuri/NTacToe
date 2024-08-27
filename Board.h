#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
using namespace std;

class GameManager{
private:

    char** board;
    int n;
    char playerChar;

public:

    GameManager(int boardSize);
    void printBoard();
    void togglePlayerChar();
    void getPlayerInput();
    bool isGameOver();
    void deleteBoard(){
        delete[] board;
    }

};


#endif // BOARD_H_INCLUDED

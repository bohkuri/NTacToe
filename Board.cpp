#include <iostream>
#include "Board.h"


using namespace std;

string checkPlayer(char playerChar);

GameManager::GameManager(int boardSize){
    n = boardSize;
    playerChar = 'X';
    board = new char*[n];

    for(int i = 0; i < n; i++){     // allocate space
        board[i] = new char[n];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            board[i][j] = '_';
        }
    }

}

void GameManager::printBoard(){
    int i = 0;
    int j = 0;
    cout << ' ';
    for (i = 0; i < n; i++){ // print top row numbers
        cout << i + 1 << ' ';

    }
    cout << endl;
    for (i = 0; i < n; i++){
        cout << i + 1;
        for (j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

void GameManager::togglePlayerChar(){
    if (playerChar == 'X'){
        playerChar = 'O';
    }
    else {
        playerChar = 'X';
    }
    return;
}

void GameManager::getPlayerInput(){
    int rowNum = 0;
    int colNum = 0;

    do{
        do{
            //prompt and input row
            cout << "Enter a valid row number: ";
            cin >> rowNum;
        }while((rowNum < 1) || (rowNum > n));
        do{
            //prompt and input column
            cout << "Enter a valid column number: ";
            cin >> colNum;
        }while((colNum < 1) || (colNum > n));
    }while((board[rowNum - 1][colNum - 1] == 'X') || (board[rowNum - 1][colNum - 1] == 'O'));
    cout << endl;

    board[rowNum - 1][colNum - 1] = playerChar;

    return;
}

bool GameManager::isGameOver(){
    int i = 0;
    int j = 0;
    int twice = 0;
    char currChar = 'X';
    int charCount = 0;
    bool boardNotFull = false;

    for (twice = 0; twice < 2; twice++){ // check rows for win (both x and o)
        for (i = 0; i < n; i++){
            charCount = 0;
            for (j = 0; j < n; j++){
                if (board[i][j] == currChar){
                    charCount++;
                }
            }
            if (charCount == n){
                cout << "Game End " << checkPlayer(currChar) << " Wins!";
                return true;
            }
        }
        currChar = 'O';
    }

    currChar = 'X'; // resets currChar to check for X win vertically, then for loop switches to check win for O
    for (twice = 0; twice < 2; twice++){ // check columns for win (both x and o)
        for (i = 0; i < n; i++){
            charCount = 0;
            for (j = 0; j < n; j++){
                if (board[j][i] == currChar){
                    charCount++;
                }
            }
            if (charCount == n){
                cout << "Game end " << checkPlayer(currChar) << " Wins!";
                return true;
            }
        }
        currChar = 'O';
    }


    currChar = 'X';
    for (twice = 0; twice < 2; twice++){// forward diagonal
        charCount = 0;

        for (i = 0; i < n; i++){
            if (board[i][i] == currChar){
                charCount++;
            }

        }
        if (charCount == n){
            cout << "Game End " << checkPlayer(currChar) << " Wins!";
            return true;
        }
        currChar = 'O';
    }

    currChar = 'X';
    for (twice = 0; twice < 2; twice++){// back diagonal win check
        charCount = 0;

        for (i = 0; i < n; i++){
            if (board[i][n - 1- i] == currChar){
                charCount++;
            }

        }
        if (charCount == n){
            cout << "Game End " << checkPlayer(currChar) << " Wins!";
            return true;
        }
        currChar = 'O';
    }

    for (i = 0; i < n; i++){// tie case
        for (j = 0; j < n; j++){
            if (board[i][j] == '_'){
                boardNotFull = true;
            }
        }
    }
    if (boardNotFull == false){
        cout << "Game End Tie";
        return true;
    }

    return false;

}

string checkPlayer(char playerChar){ // Returns player 1 or player 2 when a player wins
    if (playerChar == 'X'){
        return "Player 1";
    }
    else if (playerChar == 'O'){
        return "Player 2";
    }
    return "";
}

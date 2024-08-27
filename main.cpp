#include <iostream>
#include "Board.h"

using namespace std;

int main(){
    int n = 0;

    cout << "Enter the size of the board (between 3 and 10): ";
    cin >> n;
    while ((n < 3) || (n > 10)){
        cout << "Please enter a valid size between 3 and 10: ";
        cin >> n;
    }

    GameManager game(n);
    game.printBoard();

    while (!(game.isGameOver())){
        game.getPlayerInput();
        game.printBoard();
        game.togglePlayerChar();
    }
    game.deleteBoard();
    return 0;
}

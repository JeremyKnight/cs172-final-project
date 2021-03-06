/////////////////////////////////////////////////////////////////////////////
//  Final Project CS 172
//  Jeremy Knight
//  Kent Jones
//  December 13, 2018
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "GameObject.h"
#include "gameBoard.h"
using namespace std;

//n = number associate with player
//checks for 4 in a row
bool is4InRow(GameBoard gb, int n) {
    if(gb.check4InRow(n) || gb.check4InColum(n) || gb.check4InDiagonal(n)) {
        return true;
    }
    return false;   
}


int main() {
    string p1Name="person 1";
    string p2Name="person 2";
    bool isGameWon= false;
    GameBoard game_board = GameBoard();

    
    cout << "player 1 type a name: ";
    cin >> p1Name;
    cout << "player 2 type a name: ";
    cin >> p2Name; 
    
    cout << p1Name << " = 1" << endl;
    cout << p2Name << " = 2" << endl;

    //GAME LOOP
    while(isGameWon==false) {
        //player1's turn
        cout << p1Name << "'s turn" << endl;
        int dropPlace=-1;
        while(dropPlace>6 || dropPlace<0){
            cout << "pick a number between 0, and 6 ";
            cin >> dropPlace;
            
        }
        game_board.drop(dropPlace,1);
        game_board.printBoard();
        
        if(is4InRow(game_board, 1)) {
            cout << p1Name <<" won!" << endl;
            isGameWon=true;
            game_board.filePrintBoard(p1Name);
            return 0;
        }

        //player2's turn
        cout << p2Name << "'s turn" << endl;
        dropPlace=-1;
        while(dropPlace>6 || dropPlace<0){
            cout << ": pick a number between 0, and 6 ";
            cin >> dropPlace;
            
        }
        game_board.drop(dropPlace,2);
        game_board.printBoard();
        
        if(is4InRow(game_board, 2)) {
            cout << p2Name << " won!" << endl;
            isGameWon=true;
            game_board.filePrintBoard(p2Name);
        }
        
    }

    
}


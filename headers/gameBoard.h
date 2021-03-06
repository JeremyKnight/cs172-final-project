/////////////////////////////////////////////////////////////////////////////
//  Final Project CS 172
//  Jeremy Knight
//  Kent Jones
//  December 13, 2018
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "GameObject.h"
#include <vector>
#include <fstream>
using namespace std;

//0=nothing there
//1=p1 is there
//2=p2 is there

//class that creates and uses the gameBoard
class GameBoard{
    private:
        vector< vector<int> > board;
    public:
        GameBoard(){
            //generate number of colums
            for(int x=0;x<6; x++){
                
                vector<int> temp;
                //generate number of rows
                for(int y=0;y<7;y++){
                    temp.push_back(0);
                }
                board.push_back(temp);
            }
        }
        //returns the number at (x,y)
        int getPlace(int x, int y){
            return board.at(y).at(x);
        }
        
        //number corresponds with type of number: 1 or 2
        //checks if there is 4 in a row on a colum
        bool check4InColum(int n) {
            
            int count=0;
            for(int x=0;x<7;x++){
                for(int y=0;y<6;y++){
                    if(getPlace(x,y)==n){
                        count++;
                    } else {
                        count=0;
                    }

                    if(count==4){
                        return true;
                    }
                }
            }
            return false;
        }
        //checks if there is 4 in a row in a row
        bool check4InRow(int n) {
           for(int x=0;x<4;x++){
                for(int y=0;y<6;y++){
                    if(getPlace(x,y)==n) {
                        if(getPlace(x+1,y)==n && getPlace(x+2,y)==n && getPlace(x+3,y)==n){
                            return true;
                        }
                    }
                }
            }
            return false; 
        }
         //checks if there is 4 in a row in a diagonal
        bool check4InDiagonal(int n) {
            for(int x=0;x<4;x++){
                for(int y=3;y<6;y++){
                    if(getPlace(x,y)==n){
                        if(getPlace(x+1,y-1)==n && getPlace(x+2,y-2)==n && getPlace(x+3,y-3)==n){
                            return true;
                        }
                    }
                }
            }
            
            for(int x=3;x<7;x++) {
                for(int y=3;y<6;y++){
                    if(getPlace(x,y)==n && getPlace(x-1,y-1)==n && getPlace(x-2,y-2) && getPlace(x-3,y-3)){
                        return true;
                    }
                }
            }
            
            return false;
        }
        //prints board to terminal
        void printBoard() {
            for(int x=0;x<6;x++){
                for(int y=0;y<7;y++){
                    cout<< board.at(x).at(y) << " ";
                }
                cout << endl;
            }
        }

        //drops at colum x, and places number n at boards position.
        void drop(int x, int n){
            int i = 5;
            for(int y=0; y<i; y++) {
                if(getPlace(x,y)!=0 && y==0){
                    cout << "can't drop there." << endl;
                    break;
                } else if(getPlace(x,y+1)!=0) {
                    //cout << "got here 1" << endl;
                    board.at(y).at(x) = n;
                } 
            }
             if (getPlace(x,i)==0){
                board.at(i).at(x) = n;
             }
        }

        //prints board to a file
        void filePrintBoard(string name) {
            ofstream fout;
            fout.open("finalGameBoard.txt");

            if(fout.fail() ) {
                cout << "can't open file" << endl;
            }

            fout << "final game board:" << endl;

             for(int x=0;x<6;x++){
                for(int y=0;y<7;y++){
                    fout << board.at(x).at(y) << " ";
                }
                fout  << endl;
            }
            fout << name << " won!" << endl;
            fout.close();
        }

        


};

#endif
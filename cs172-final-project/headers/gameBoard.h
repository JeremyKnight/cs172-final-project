#include <iostream>
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "GameObject.h"
#include <vector>
using namespace std;

//0=nothing there
//1=p1 is there
//2=p2 is there

class GameBoard{
    private:
        vector< vector<int> > board;
    public:
        GameBoard(){
            //generate number of rows
            for(int x=0;x<6; x++){
                vector<int> temp;
                //generate number of colums
                for(int y=0;y<7;y++){
                    temp.push_back(0);
                }
                board.push_back(temp);
            }
        }

        int getPlace(int x, int y){
            return board.at(x).at(y);
        }
        
        //number corresponds with type of number: 1 or 2
        bool check4InRow(int n) {
            int count=0;
            for(int x=0;x<7;x++){
                for(int y=0;y<6;y++){
                    if(board.at(x).at(y)==n){
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

        bool check4inColum(int n) {

        }

        bool check4inDiagonal(int n) {

        }
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
            for(int y=0; y<6; y++) {
                if(board.at(x).at(y)!=0 && y==0){
                    cout << "can't drop there." << endl;
                    break;
                } else if(board.at(x).at(y)!=0) {
                    board.at(x).at(y-1) = n;
                } 
            }
             if (board.at(x).at(5)==0){
                board.at(x).at(5) = n;
             }
        }

        


};

#endif
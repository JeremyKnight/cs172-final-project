#include <iostream>
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "GameObject.h"
#include <vector>
using namespace std;

//0=nothing there
//1=p1 is there
//2=p2 is there

//x and y are flipped
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
            return board.at(y).at(x);
        }
        
        //number corresponds with type of number: 1 or 2
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

        bool check4InRow(int n) {
            int count=0;

            if(count==4) {
                return true;
            }
            return false;
        }

        bool check4InDiagonal(int n) {
            return false;
        }
        void printBoard() {
            for(int y=0;y<6;y++){
                for(int x=0;x<7;x++){
                    cout<< getPlace(x,y) << " ";
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

        


};

#endif
#ifndef STACK_COLORSQUARES_H
#define STACK_COLORSQUARES_H
#include <iostream>
using namespace std;

class ColorSquares{
public:
    ColorSquares(int numSq, string col){
        numSquares = numSq; 
        SqColor = col; 
    }
    int getNumeSquares(){
        return numSquares;
    }
    void setNumSquares(int num){
        numSquares = num; 
    } 
    void setColor(string col){
        SqColor = col; 
    }

    string getColor(){
        return SqColor; 
    }

    void subNumSquares(int sub){
        numSquares-=sub; 
    }


private:
    int numSquares; 
    string SqColor; 
};

#endif

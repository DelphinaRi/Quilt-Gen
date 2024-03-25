#include <iostream>
using namespace std;

class ColorSquares{
public:
    ColorSquares(){
        numSquares = 0; 
        SqColor = "null"; 
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
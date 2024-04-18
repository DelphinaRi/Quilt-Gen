#ifndef STACK_QUILTTOP_H
#define STACK_QUILTTOP_H
#include <iostream>
#include <vector>
#include "Patterns.h"
// #include "quiltTop.cpp"
#include "ColorSquares.h"
#include "Node.h"
using namespace std;

class quiltTop
{
public:
    quiltTop(int len, int wid);

    void getTotNum(){
        totalNumOfBoxes = length*width; 
        cout << totalNumOfBoxes << "\n"; 
    }

    void generateQuilt();
    void readInPatterns(vector<Patterns> p);
    void readInSquares(vector<ColorSquares> c);
    void shufflePatterns();
    // void shuffleColors();
    // void patternDisplay(int *a[int w]);


private:
    int totalNumOfBoxes=0; 
    int length=0;
    int width =0; 
    vector<Patterns> patterns;
    vector<ColorSquares> squares; 
    
};


#endif



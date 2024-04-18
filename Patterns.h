#ifndef STACK_PATTERNS_H
#define STACK_PATTERNS_H
#include <iostream>
using namespace std;

class Patterns
{
public:
    Patterns();
    //just  hella getters and setters 
    void setName(string n){name = n;};
    void setNum(string n){totalNum = n;};
    void setPattern(string p){pat = p;};
    void setLength(string l){lenght = l;};
    void setWidth(string w){width = w;};
    void setNumColors(string c){numCol = c;};

    string getName(){return name;};
    string getPatteren(){return pat;};
    int getNum(){return toNumInt;};
    int getLength(){return lenInt;};
    int getWidth(){return widInt;};
    int getNumColors(){return numberColors;};

    void convertToInt(); 


private:
    string name;
    string totalNum;
    string pat; 
    string lenght;
    string width;
    string numCol; 

    int toNumInt=0; 
    int lenInt=0; 
    int widInt =0; 
    int numberColors=0; 
    
};

Patterns::Patterns(/* args */)
{
    // cout << "ge/tting patters\n"; 
}

void Patterns:: convertToInt(){
    toNumInt  = stoi(totalNum);
    lenInt = stoi(lenght);
    widInt = stoi(width); 
    numberColors = stoi(numCol); 

}

#endif




#ifndef STACK_NODE_H
#define STACK_NODE_H
#include <iostream>
#include <string>
using namespace std; 
class Node
{
public:
    Node();
    bool empty(){return em;}; 
    void fill(){em = false;}; 
    string display(){return d;};
    void changeDisplay(string s){d = s;}; 
    string showColor(){return color;};
    void changeColor(string col){color = col;}; 
    void changeName(string n){name = n;}; 
    
private:
    bool em = true;
    string name; 
    string d = "-" ; 
    string color = "---"; 

};

Node::Node(/* args */)
{
}




#endif

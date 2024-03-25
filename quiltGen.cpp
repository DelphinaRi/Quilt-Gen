#include <iostream>
#include <map>
#include <string>


using namespace std; 
//main map of all the stuff 
 map<string, int> colors;


//fucntions u know how it be 
void userInput();

int main(){
    cout<< "weclome to the quilt generator" << "\n"; 
    //get user input 
    userInput(); 


    return 0; 
}

void userInput(){
    //gets user inputs of amount of squares and colors 
    int userIn;
    string color; 
    int numOfSquares; 
    while(1==1){
        cout<< "what do you want to do \n1: Add a type of squares \n2: Generate the quilt Pattern\n" ;
        cin>> userIn;
        cout << userIn;
        if(userIn == 1){
            cout<< "input the color\n"; 
            cin>> color;
            cout <<"input the number of boxes in that color\n";
            cin >> numOfSquares;
            colors[color] = numOfSquares; 
            cout << color << " " << numOfSquares << "\n"; 


            // colors
        }else if(userIn ==2){
            break;
        }else{
            cout<< "wrong input try again\n"; 
            continue;
        }
        

    }

}
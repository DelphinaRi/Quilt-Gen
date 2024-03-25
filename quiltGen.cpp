#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "ColorSquares.h"

using namespace std;
// main map of all the stuff
vector<ColorSquares> colors;

// fucntions u know how it be
void userInput();
void testSquares();

int main()
{
    cout << "weclome to the quilt generator"
         << "\n";
    // get user input
    userInput();
    // testSquares();

    return 0;
}

void userInput()
{
    // gets user inputs of amount of squares and colors
    int userIn;
    string color;
    int numOfSquares;
    while (1 == 1)
    {
        cout << "what do you want to do \n1: Add a type of squares \n2: Generate the quilt Pattern\n3: Show previous inputs\n";
        cin >> userIn;
        cout << userIn << "\n";
        if (userIn == 1)
        {
            
            cout << "input the color\n";
            cin >> color;
            cout << "input the number of boxes in that color\n";
            // temp.setNumSquares(numOfSquares);
            cin >> numOfSquares;
            ColorSquares temp(numOfSquares, color);
            colors.push_back(temp); 
            // colors[color] = numOfSquares;
            cout << color << " " << numOfSquares << "\n";

            // colors
        }
        else if (userIn == 2)
        {
            break;
        }
        else if (userIn == 3)
        {
            cout << colors.size() << "\n";
            for (size_t i = 0; i < colors.size(); i++)
            {
                cout << i << ": " << colors.at(i).getColor() << "---" << colors.at(i).getNumeSquares() << "\n";
            }
        }
        else
        {
            cout << "\nwrong input try again\n";
            continue;
        }
    }
    // for (size_t i = 0; i < colors.size(); i++)
    // {
    //     cout << colors.at(i).getColor() << "---" << colors.at(i).getNumeSquares() << "\n";
    // }
}

void testSquares()
{
    ColorSquares c(10, "blue" );
    // c.setNumSquares(10);
    // c.setColor("blue");

    cout << c.getColor() << "  " << c.getNumeSquares() << "\n";
    c.subNumSquares(5);
    c.setColor("red");
    cout << c.getColor() << "  " << c.getNumeSquares() << "\n";
}
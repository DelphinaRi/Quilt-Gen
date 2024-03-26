#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "ColorSquares.h"

using namespace std;


// main map of all the stuff
vector<ColorSquares> colors;

// fucntions u know how it be
void userInput();
void testSquares();
void getSize();
void presetSquaresCauseImlaze();

void printColors()
{
    cout << colors.size() << "\n";
    for (size_t i = 0; i < colors.size(); i++)
    {
        cout << i << ": " << colors.at(i).getColor() << "---" << colors.at(i).getNumeSquares() << "\n";
    }
}

int main()
{
    cout << "weclome to the quilt generator"
         << "\n";
    // get user input
    // string s1 = to_string(10);
    // string s2 = to_string(20);
    // string s = s1 + "x" + s2; ;
    // cout << s;
    presetSquaresCauseImlaze();
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
        // cout << userIn << "\n";
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
            getSize();
            break;
        }
        else if (userIn == 3)
        {
            printColors();
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
    ColorSquares c(10, "blue");
    // c.setNumSquares(10);
    // c.setColor("blue");

    cout << c.getColor() << "  " << c.getNumeSquares() << "\n";
    c.subNumSquares(5);
    c.setColor("red");
    cout << c.getColor() << "  " << c.getNumeSquares() << "\n";
}

void presetSquaresCauseImlaze()
{
    ColorSquares a(10, "blue");
    ColorSquares b(20, "yellow");
    ColorSquares c(15, "red");
    ColorSquares d(5, "green");
    ColorSquares e(5, "purple");
    ColorSquares f(20, "pink");
    ColorSquares g(30, "magenta");
    colors.push_back(a);
    colors.push_back(b);
    colors.push_back(c);
    colors.push_back(d);
    colors.push_back(e);
    colors.push_back(f);
    colors.push_back(g);
}

void getSize()
{
    int size1;
    int size2;
    int total = 0;
    map<string, int> possibleSizes;
    map<string, int> finalSizes;
    // gets the max amount of squares available to use
    for (size_t i = 0; i < colors.size(); i++)
    {
        total += colors.at(i).getNumeSquares();
    }
    cout << total << "\n";

    for (size_t i = 0; i < colors.size(); i++)
    {
        // if a particular dimension is less than the max amount of squares it becomes an option
        size1 = colors.at(i).getNumeSquares();
        for (size_t j = 0; j < colors.size(); j++)
        {
            size2 = colors.at(j).getNumeSquares();
            int compare = size1 * size2;
            if (total >= compare)
            { // makes sure the size is not larger than the max amount of squares
                string size1S = to_string(size1);
                string size2S = to_string(size2);
                string s = size1S + "x" + size2S;
                possibleSizes.insert({s, compare});
            }
        }
    }

    // sorts the possible options from lowest to highest
    cout << "------\n";
    cout << "These are the options for quilt sizes. Please type which one you would you like\n";
    // sort(possibleSizes);
    int max = 0;
    for (auto it = possibleSizes.cbegin(); it != possibleSizes.cend(); ++it)
    {
        if (it->second > max)
        { // finds the maximum value in the quilt generator
            max = it->second;
        }
        // cout << it->first << " " << it->second << "\n";
    }
    // cout << "max =" << max << "\n";
    for (auto it = possibleSizes.cbegin(); it != possibleSizes.cend(); ++it)
    {
        if (it->second == max)
        { // if the value matches with the max then it gets added to final map
            finalSizes.insert({it->first, it->second});
        }
    }

    for (auto it = finalSizes.cbegin(); it != finalSizes.cend(); ++it)
    {
        if (it->second > max)
        {
            max = it->second;
        }
        cout << it->first << " " << it->second << "\n";
    }
    int height;
    int width;
    cin >> height;
    cout << "x\n";
    cin >> width;
}


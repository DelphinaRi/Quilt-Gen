#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#include "ColorSquares.h"
#include "quiltTop.h"
#include "quiltTop.cpp"
#include "Patterns.h"

// holds all the colors2
vector<ColorSquares> colors;
// holds all the pattern objects
vector<Patterns> patterns;

// fucntions u know how it be
// just makes the user input
void userInput();
// just a little test thing for me
void testSquares();
// how the size of the quilt gets decided
void getSize();
// exactly what it says on the tin
void presetSquaresCauseImlaze();

void readInPatters();

void printColors()
{
    std::cout << colors.size() << "\n";
    for (size_t i = 0; i < colors.size(); i++)
    {
        std::cout << i << ": " << colors.at(i).getColor() << "---" << colors.at(i).getNumeSquares() << "\n";
    }
}

int main()
{
    std::cout << "weclome to the quilt generator"
              << "\n";
    // get user input
    // string s1 = to_string(10);
    // string s2 = to_string(20);
    // string s = s1 + "x" + s2; ;
    // cout << s;
    presetSquaresCauseImlaze();
    readInPatters();
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
            // quiltTop quilt();
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
    ColorSquares a(9, "a");
    ColorSquares b(9, "b");
    ColorSquares c(9, "c");
    ColorSquares d(9, "d");
    ColorSquares e(9, "e");
    ColorSquares f(9, "f");
    ColorSquares g(9, "g");
    ColorSquares h(9, "h");
    ColorSquares i(9, "i");
    ColorSquares j(9, "j");
    
    ColorSquares k(9, "k");
    ColorSquares l(9, "l");
    ColorSquares m(9, "m");

    ColorSquares n(9, "n");
    ColorSquares o(9, "o");
    ColorSquares p(6, "p");

    ColorSquares q(40, "q");
    ColorSquares filler(0, "fill");


    colors.push_back(a);
    colors.push_back(b);
    colors.push_back(c);
    colors.push_back(d);
    colors.push_back(e);
    colors.push_back(f);
    colors.push_back(g);
    colors.push_back(h);
    colors.push_back(i);
    colors.push_back(j);
    colors.push_back(k);
    colors.push_back(l);
    colors.push_back(m);
    colors.push_back(n);
    colors.push_back(o);
    colors.push_back(p);
    colors.push_back(q);
    colors.push_back(filler);
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
    // declares the quilt object
    quiltTop quilt(height, width);

    // FOR SOME REASON THIS IS WHERE IM PUTTING ALL THE CODE TO GENERATE THE QUILT. IDK WHY EITHER
    // this fucntion gets the size of the quilt and the max number of boxes needed
    quilt.getTotNum();
    // these get the vectors for squares and patterns into the quilt class
    quilt.readInSquares(colors);
    quilt.readInPatterns(patterns);
    // it took a long tome --- and was a long road--- but this actually generates the quilt top
    // heavenly light -- angel chorus
    quilt.generateQuilt();
}

void readInPatters()
{
    string str;
    // Patterns temp;
    string name;
    string totalNum;
    string len;
    string width;
    ifstream file("Patterns.txt");
    string runTimes;
    string numColors;
    getline(file, runTimes);
    cout << "runtime = " << runTimes << "\n---\n\n";
    int runT = stoi(runTimes);

    for (size_t i = 0; i < runT; i++)
    {
        Patterns temp;

        getline(file, str, '-');
        cout << str << "\n";
        temp.setPattern(str);

        getline(file, name, '-');
        cout << name << "\n";
        temp.setName(name);

        getline(file, totalNum, '-');
        cout << totalNum << "\n";
        temp.setNum(totalNum);

        getline(file, len, 'x');
        cout << len << "\n";
        temp.setLength(len);

        getline(file, width, '-');
        cout << width << "\n";
        temp.setWidth(width);

        getline(file, numColors);
        cout << numColors << "\n";
        temp.setNumColors(numColors);

        // cout << temp.getName() << "\n";
        // cout << temp.getPatteren();
        // cout << temp.getNumColors();
        patterns.push_back(temp);

        // cout << temp.getName() << "      sjfbjdbfsd    ";

        // cout << temp.getName() << "--" << temp.getNum() << "--" << temp.getLength() << "--" << temp.getWidth() <<temp.getPatteren() << "\n";
    }

    cout << "\n-----------\n";

    for (size_t i = 0; i < patterns.size(); i++)
    {
        patterns.at(i).convertToInt();
        cout << patterns.at(i).getName() << "--" << patterns.at(i).getNum() << "--" << patterns.at(i).getLength() << "--" << patterns.at(i).getWidth() << "--" << patterns.at(i).getNumColors() << " " << patterns.at(i).getPatteren() << "\n";
    }

    // while (getline(file, str))
    // {
    //     cout << str << "\n";
    // }
}

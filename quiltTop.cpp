#include "quiltTop.h"
#include <bits/stdc++.h>
#include <random>
// using namespace std;

quiltTop::quiltTop(int len, int wid)
{
    length = len;
    width = wid;
    totalNumOfBoxes = len * wid;
}

void quiltTop::generateQuilt()
{
    std::cout << "generating quilt top\n";
    // 2d array creation
    Node plex[length][width];
    // plex[0][1].fill();
    // plex[5][5].fill();
    // plex[8][8].fill();

    // these 2 loops just print out the 2d arrays
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            std::cout << plex[i][j].empty() << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    // showing the new pattern at each thing
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            std::cout << plex[i][j].display() << " ";
        }
        std::cout << "\n";
    }

    // sets up the vairables to be able to loop though the 2d arrary didnt want to just use the 2 nested for loops because then I would have like 20 nested for loops and thats too many
    int i = 0;
    int j = 0;

    int x = 0;
    int y = 0;

    // while(1==1){
    for (size_t a = 0; a < length * width; a++)
    {
        bool emptyL = true;
        bool emptyW = true;

        if (plex[i][j].empty() == true)
        {
            // plex[i][j].fill();

            for (size_t b = 0; b < patterns.size(); b++)
            {
                int it = 0;
                int megaIt = 0;
                // cout << patterns.at(b).getLength() << "   " << patterns.at(b).getWidth() << "\n";
                // this has to loop through the pattern shape like it is a 2d array, very annoying I know
                // reasonably I could do the think that i did with i and j here and not do a nested for loop, but as you can see im unfortunantly already commited
                for (size_t c = 0; c < patterns.at(b).getLength(); c++)
                {
                    emptyL = true;
                    for (size_t d = 0; d < patterns.at(b).getWidth(); d++)
                    {
                        // cout << i << "  " << j << "\n";
                        // if the code goes over either edge then it moves on to the next one
                        if (j + 1 > length)
                        {
                            b++;
                        }
                        // if(j == width){
                        //     b++;
                        // }
                        if (j + patterns.at(b).getLength() > length)
                        {
                            std::cout << i + d << "  " << j + c << "\n";
                            // std::cout << "goes over the edge\n";
                            b++;
                        }
                        if (i + patterns.at(b).getWidth() > width)
                        {
                            std::cout << i + d << "  " << j + c << "\n";
                            // std::cout << "goes over the vertical edge\n";
                            b++;
                        }
                        if (plex[i + d][j + c].empty() == false)
                        {
                            std::cout << i + d << "  " << j + c << "\n";
                            emptyL = false;
                            // std::cout << "cant place here\n";
                            b++;
                        }
                    }
                }
                if (emptyL == true)
                {

                    // if the pattern fits in the area then the node is marked empty and given a name

                    std::cout << patterns.at(b).getName() << "\n";
                    string newName = patterns.at(b).getName();
                    for (size_t c = 0; c < patterns.at(b).getLength(); c++)
                    {

                        for (size_t d = 0; d < patterns.at(b).getWidth(); d++)
                        {

                            std::cout << i + d << "   " << j + c << "\n";
                            plex[i + d][j + c].fill();

                            // gets the color at the thing
                            // vector<int> colorsNeeded;
                            // while(1 ==1){

                            // }
                            // for(int e =0; e < patterns.at(b).getNumColors(); e++){
                            //     // if(colors.at(rand))

                            //     cout << "color " << e+1 ;
                            // }

                            // for (size_t e = 0; e < patterns.at(b).getNumColors(); e++)
                            // {
                            //     // int colNum =
                            //     // if(squares.at(rand()).getNumeSquares() > patterns.at(b).getNum()/ patterns.at(b).getNumColors()){
                            // }
                            // int
                        }

                        // string dis(patterns.at(b).getPatteren());

                        // const char *str = dis.c_str();

                        // char ch = dis.at(0);
                        // string ch = dis[4];
                        // plex[i + d][j + c].changeDisplay(str[4]);
                    }
                    // std::cout << "gets to this point\n";

                    while (1 == 1)
                    {
                        // cout << squares.at(it).getNumeSquares() <<"\n"<< b << "\n";
                        // cout << patterns.at(b).getNum() <<"\n";
                        // cout << patterns.at(b).getNumColors() << "\n";
                        if (squares.at(it).getNumeSquares() >= patterns.at(b).getNum() / patterns.at(b).getNumColors())
                        {
                            // cout << "ran once\n";
                            squares.at(it).subNumSquares(patterns.at(b).getNum() / patterns.at(b).getNumColors());
                            std::cout << "color " << it + 1 << " will be " << squares.at(it).getColor() << "\n";
                            it++;
                            megaIt++;
                        }
                        else
                        {
                            it++;
                        }
                        if (megaIt == patterns.at(b).getNumColors())
                        {
                            break;
                        }
                        if (it >= squares.size())
                        {
                            it = 0;
                        }
                    }
                    // std::cout << "---------------\n\n";
                    // // prints them again to see the difference
                    // for (size_t i = 0; i < length; i++)
                    // {
                    //     for (size_t j = 0; j < width; j++)
                    //     {
                    //         std::cout << plex[i][j].empty() << " ";
                    //     }
                    //     std::cout << "\n";
                    // }
                    // std::cout << "------------------\n\n";

                    b = patterns.size();
                }
            }
            shufflePatterns();
        }
        // cout << emptyL << "\n";

        // cout << i << "   " << j << "\n";

        // if (i == length && j == width)
        // {
        //     break;
        // }

        else
        {
            // std::cout << "node is already taken \n";
        }
        // cout << i << "  " << j <<"\n";
        if (j == width-1)
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }

    for (size_t i = 0; i < squares.size(); i++)
    {
        std::cout << "number of " << squares.at(i).getColor() << " left: " << squares.at(i).getNumeSquares() << "\n";
    }

    std::cout << "---------------\n\n";
    // prints them again to see the difference
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            std::cout << plex[i][j].empty() << " ";
        }
        std::cout << "\n";
    }
    std::cout << "------------------\n\n";

    // showing the new pattern at each thing
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            std::cout << plex[i][j].display() << " ";
        }
        std::cout << "\n";
    }
}

void quiltTop::readInSquares(vector<ColorSquares> c)
{
    squares = c;
}

void quiltTop::readInPatterns(vector<Patterns> p)
{
    patterns = p;
    for (int i = 0; i < patterns.size(); i++)
    {
        patterns.at(i).convertToInt();
        // int temp = patterns.at(i).getLength();
        // cout << temp <<"\n";
    }
}

void quiltTop::shufflePatterns()
{
    unsigned seed = 0;
    shuffle(patterns.begin(), patterns.end() - 1, default_random_engine(seed));
    shuffle(squares.begin(), squares.end(), default_random_engine(seed));

    std::cout << "---\n";
    for (size_t i = 0; i < patterns.size(); i++)
    {
        std::cout << patterns.at(i).getName();
    }
    std::cout << "---\n";
}

// void quiltTop::shuffleColors()
// {
//     unsigned seed = 0;
//     std::shuffle(squares.begin(), patterns.end() - 1, default_random_engine(seed));

//     // cout << "---\n";
//     // for (size_t i = 0; i < patterns.size(); i++)
//     // {
//     //     cout << patterns.at(i).getName();
//     // }
//     // cout << "---\n";
// }
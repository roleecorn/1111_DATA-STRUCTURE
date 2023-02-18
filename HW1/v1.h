#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>
#include "sp.h"
using namespace std;
void transpose1(string infile,string outf)
{
    std::ofstream outfile;

    outfile.open(outf, std::ios_base::app); // append instead of overwrite

    string myText;
    ifstream MyReadFile(infile);
    // get row and col
    getline(MyReadFile, myText);
    std::vector<std::string> ret = split(myText, ' ');
    // use flag to know reading row or col
    int r, co, flag = 0;
    for (auto &s : ret)
    {
        

        int number = std::stoi(s);
        if (flag == 0)
        {
            r = number;
            flag++;
        }
        else
        {
            co = number;
        }
    }

    int ma[r][co];
    int rma[co][r];
    // init to zero matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < co; j++)
        {
            ma[i][j] = 0;
        }
    }
    flag = 0;
    int ra, c, v;
    while (getline(MyReadFile, myText))
    {
        std::vector<std::string> ret = split(myText, ' ');
        for (auto &s : ret)
        {
            // cout << s << "\n";
            int number = std::stoi(s);
            if (flag == 0)
            {
                // its a row
                ra = number;
                flag++;
            }
            else if (flag == 1)
            {
                // it's a col
                c = number;
                flag++;
            }
            else if (flag == 2)
            {
                // it's a value
                v = number;
                ma[ra][c] = v;
                flag = 0;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < co; j++)
        {
            rma[j][i]=ma[i][j];
        }
    }
    for (int i = 0; i < co; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if(rma[i][j] !=0){
                outfile << i<<" "<<j<< " "<<rma[i][j]<< endl;
            }
        }
    }


    MyReadFile.clear();
    MyReadFile.seekg(0);
    // write file append
}

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "sp.h"
using namespace std;
void transpose2(string infile, string outf)
{
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
    // use flag to check it is row ,col or value
    flag = 0;
    int c = 0;
    int rowofspr = 1024;
    int colofaspr = 3;
    // 1024*3 array to save input
    int spr[rowofspr][colofaspr];

    // save input to 3*1024 array spr
    while (getline(MyReadFile, myText))
    {
        std::vector<std::string> ret = split(myText, ' ');
        for (auto &s : ret)
        {
            // cout << s << "\n";
            int number = std::stoi(s);
            if (flag != 2)
            {
                // its a row
                spr[c][flag] = number;
                flag++;
            }
            else if (flag == 2)
            {
                // it's a col
                spr[c][flag] = number;
                flag = 0;
                c++;
            }
        }
    }
    std::ofstream outfile;
    // transforn
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    for (int j = 0; j < co; j++)
    {
        for (int i = 0; i < c; i++)
        {
            if (j == spr[i][1])
            {
                outfile << spr[i][1] << " " << spr[i][0] << " " << spr[i][2] << endl;
            }
        }
    }
    MyReadFile.clear();
    MyReadFile.seekg(0);
}

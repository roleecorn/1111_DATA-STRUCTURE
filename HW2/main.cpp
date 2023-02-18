#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>
#include <queue>
#include <stack>
using namespace std;
#include "DFS.h"
using std::filesystem::exists;
int main()
{
    string infile = "maze.txt";
    cout<<"enter filename:";
    cin>>infile;
    if (!exists(infile)){
        cout<<"not a file"<<endl;
        return 0;
    }
    string outf = "h2.out";
    vector<vector<char>> matrix2;
    ifstream MyReadFile(infile);
    string myText;
    // read maze to vector
    for (int i = 0; i < 17; i++)
    {
        getline(MyReadFile, myText);
        vector<char> tmp;
        for (int j = 0; j < 17; j++)
        {
            tmp.push_back(myText[j]);
        }
        matrix2.push_back(tmp);
    }
    std::ofstream outfile;
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    // output the maze to target file
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            outfile << matrix2[i][j];
        }
        outfile << endl;
    }
    // method to slove maze, the code in DFS.c
    Solution sol;
    // the start position
    vector<int> st{1, 0};
    int a = sol.nearestExit(matrix2, st, outf);
    return 0;
};
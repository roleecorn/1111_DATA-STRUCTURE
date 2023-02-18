#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
// using std::filesystem::exists;
#include <fstream>
#include "treenode.h"
#include "insert.h"
#include "delete.h"
#include "search.h"
#include "print.h"
int main()
{
    TreeNode root(-1);
    string modet, myText;
    string outf = "out.txt";
    std::ofstream outfile;
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    string infile = "sample.txt";
    cout<<"Enter file name:";
    cin>>infile;
    ifstream MyReadFile(infile);

    while (true)
    {
        outfile << endl;
        outfile << "(I)nsert a number." << endl;
        outfile << "(D)elete a number." << endl;
        outfile << "(S)earch a number." << endl;
        outfile << "(P)rint 4 kinds of orders." << endl;
        outfile << "(E)xit" << endl;
        outfile << endl;

        cout << endl;
        cout << "(I)nsert a number." << endl;
        cout << "(D)elete a number." << endl;
        cout << "(S)earch a number." << endl;
        cout << "(P)rint 4 kinds of orders." << endl;
        cout << "(E)xit" << endl;
        cout << endl;
        getline(MyReadFile, modet);
        TreeNode *tmp;
        if (modet[0] == 'I' || modet[0] == 'i')
        {
            outfile << "Insert" << endl;
            getline(MyReadFile, myText);
            tmp = insert(&root, myText, outf);
        }
        else if (modet[0] == 'E' || modet[0] == 'e')
        {
            outfile << "Exit" << endl;
            cout << "Exit" << endl;
            break;
        }
        else if (modet[0] == 'D' || modet[0] == 'd')
        {
            outfile << "Delete:" << endl;
            cout << "Delete:" << endl;
            getline(MyReadFile, myText);
            if (!root.left)
            {
                outfile << "empty tree" << endl;
                cout << "empty tree" << endl;
                std::vector<std::string> ret = split(myText, ' ');
                for (string &s : ret)
                {
                    if(stoi(s)==-1){
                        break;
                    }
                    outfile << "Number " << s << " is not exist." << endl;
                    cout << "Number " << s << " is not exist." << endl;
                }
                continue;
            }
            delnode(&root, myText, outf);
        }
        else if (modet[0] == 's' || modet[0] == 'S')
        {
            outfile << "Search:" << endl;
            cout << "Search:" << endl;
            getline(MyReadFile, myText);
            if (root.left)
            {
                searchnode(root.left, myText, outf);
            }
            // else
            // {
            //     cout << "tree empty" << endl;
            // }
        }
        else if (modet[0] == 'P' || modet[0] == 'p')
        {
            outfile << "Print:" << endl;
            cout << "Print:" << endl;
            if (root.left)
            {
                printnode(root.left, outf);
            }
            // else
            // {
            //     cout << "tree empty" << endl;
            // }
        }
        else
        {
            outfile << "invalue" << endl;
            cout << "invalue" << endl;
        }
    }
    return 0;
};
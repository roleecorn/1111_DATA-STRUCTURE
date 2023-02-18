#ifndef SEARCH

#define SEARCH
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "treenode.h"
int checknode(TreeNode *root, int val)
{
    TreeNode *tmp;
    tmp = root;
    while (true)
    {
        if (tmp->val == val)
        {
            return 1;
        }
        if (tmp->left and tmp->val > val)
        {
            tmp = tmp->left;
            continue;
        }
        if (tmp->right and tmp->val < val)
        {
            tmp = tmp->right;
            continue;
        }
        return 0;
    }
}

TreeNode *searchnode(TreeNode *root, string myText, string outf)
{
    std::vector<std::string> ret = split(myText, ' ');
    int tt, flag;
    TreeNode *tmp;
    std::ofstream outfile;
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    for (string &s : ret)
    {
        tt = stoi(s);
        if (tt == -1)
        {
            return root;
        }
        flag = checknode(root, tt);
        if (flag)
        {
            outfile << "Bingo! " << tt << " is found." << endl;
            cout << "Bingo! " << tt << " is found." << endl;
        }else{
            outfile << "Sorry! " << tt << " is not found." << endl;
            cout << "Sorry! " << tt << " is not found." << endl;
        }
    }

    return root;
}
#endif
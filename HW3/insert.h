#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "treenode.h"
#include "sp.h"
TreeNode *insert(TreeNode *root, string myText, string outf)
{
    std::vector<std::string> ret = split(myText, ' ');
    std::ofstream outfile;
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    int tt;
    TreeNode *tmp;
    for (string &s : ret)
    {
        tt = stoi(s);
        if (root->left)
        {
            tmp = root->left;
        }
        else
        {
            root->left = new TreeNode(tt);
            outfile << "Number " << tt << " is inserted." << endl;
            cout << "Number " << tt << " is inserted." << endl;
            continue;
        }

        cout << tt << " ";
        if (tt == -1)
        {
            return root;
        }

        while (true)
        {
            if (tmp->left and tmp->val > tt)
            {
                tmp = tmp->left;
                continue;
            }
            if (tmp->right and tmp->val < tt)
            {
                tmp = tmp->right;
                continue;
            }
            break;
        }
        if (tmp->val == tt)
        {
            outfile << "Error! Number " << tt << " exists." << endl;
            cout << "Error! Number " << tt << " exists." << endl;
            continue;
        }
        if (tmp->val > tt)
        {
            tmp->left = new TreeNode(tt);
            outfile << "Number " << tt << " is inserted." << endl;
            cout << "Number " << tt << " is inserted." << endl;
            continue;
        }
        if (tmp->val < tt)
        {
            tmp->right = new TreeNode(tt);
            outfile << "Number " << tt << " is inserted." << endl;
            cout << "Number " << tt << " is inserted." << endl;
        }
    }

    return root;
}
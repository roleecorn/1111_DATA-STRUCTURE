#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "treenode.h"
#include "search.h"
TreeNode *succesor(TreeNode *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
TreeNode *delaNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->val > key)
    {
        root->left = delaNode(root->left, key);
        return root;
    }else if (root->val < key)
    {
        root->right = delaNode(root->right, key);
        return root;
    }
    else 
    {
        // case 1 zero child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 1 with one children
        if (root->left == NULL and root->right != NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL and root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        // case 3 with both children
        TreeNode *replace = root->right;
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        root->val = replace->val;
        root->right = delaNode(root->right, replace->val);
        return root;
    }
    
}
TreeNode *delnode(TreeNode *root, string myText, string outf)
{
    std::vector<std::string> ret = split(myText, ' ');
    int tt;
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
        if (!checknode(root->left, tt))
        {
            outfile<<"Number "<<tt<<" is not exist."<<endl;
            cout<<"Number "<<tt<<" is not exist."<<endl;
            continue;
        }
        outfile<<"Number "<<tt<<" is deleted."<<endl;
        cout<<"Number "<<tt<<" is deleted."<<endl;
        delaNode(root->left, tt);
    }

    return root;
}
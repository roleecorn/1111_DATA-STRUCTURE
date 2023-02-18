#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "treenode.h"
#include <queue>
void prefix(TreeNode *node, queue<int> *val)
{
    val->push(node->val);
    if (node->left)
        prefix(node->left, val);
    if (node->right)
        prefix(node->right, val);
}
void postfix(TreeNode *node, queue<int> *val)
{
    if (node->left)
        postfix(node->left, val);
    if (node->right)
        postfix(node->right, val);
    val->push(node->val);
}
void levelorder(TreeNode *node, queue<int> *val)
{
    queue<TreeNode> qq;
    TreeNode anode;
    qq.push(*node);

    while (!qq.empty())
    {
        anode = qq.front();
        val->push(anode.val);
        qq.pop();
        if (anode.left)
        {
            qq.push(*anode.left);
        }
        if (anode.right)
        {
            qq.push(*anode.right);
        }
    }
}
void infix(TreeNode *node, queue<int> *val)
{
    if (node->left)
        infix(node->left, val);
    val->push(node->val);
    if (node->right)
        infix(node->right, val);
}
void printnode(TreeNode *root, string outf)
{
    std::ofstream outfile;
    outfile.open(outf, std::ios_base::app); // append instead of overwrite
    queue<int> val;
    int tmp;
    outfile << "The tree in prefix order: ";
    cout << "The tree in prefix order: ";
    prefix(root, &val);
    while (!val.empty())
    {
        tmp = val.front();
        val.pop();
        outfile << tmp << " ";
        cout << tmp << " ";
    }
    outfile << endl;
    outfile << "The tree in infix order: ";
    cout << endl;
    cout << "The tree in infix order: ";
    infix(root, &val);
    while (!val.empty())
    {
        tmp = val.front();
        val.pop();
        outfile << tmp << " ";
        cout << tmp << " ";
    }
    outfile << endl;
    outfile << "The tree in post order: ";
    cout << endl;
    cout << "The tree in post order: ";
    postfix(root, &val);
    while (!val.empty())
    {
        tmp = val.front();
        val.pop();
        outfile << tmp << " ";
        cout << tmp << " ";
    }
    outfile << endl;
    outfile << "The tree in level order: ";
    cout << endl;
    cout << "The tree in level order: ";
    levelorder(root, &val);
    while (!val.empty())
    {
        tmp = val.front();
        val.pop();
        outfile << tmp << " ";
        cout << tmp << " ";
    }
    outfile << endl;
    cout << endl;
    return;
}
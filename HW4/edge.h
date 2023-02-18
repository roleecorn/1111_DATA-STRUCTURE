#ifndef EDGE_H

#define EDGE_H
#include <iostream>
using namespace std;
struct edge
{
    /* data */
    string startpoint;
    string endpoint;
    int value;
};
struct node
{
    /* data */
    string name;
    int dist;
};
bool mycompare(edge e1, edge e2)
{
    return e2.value > e1.value;
}
bool mycompare2(std::pair<string, int> e1, std::pair<string, int> e2)
{
    return e2.second > e1.second;
}
#endif
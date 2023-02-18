#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
#include "sp.h"
#include "edge.h"
#include <set>
#include <map>
#include <algorithm>
const int INF = 1000000000;
int main()
{
    string n_of_edge, myText, startpoint;
    string outf = "outd.txt";
    std::ofstream outfile;
    outfile.open(outf); // append instead of overwrite
    string infile = "sample_d.txt";
    cout << "Enter file name:";
    cin>>infile;
    ifstream MyReadFile(infile);
    getline(MyReadFile, n_of_edge);
    int number = std::stoi(n_of_edge);
    vector<edge> edges;
    for (int i = 0; i < number; i++)
    {
        getline(MyReadFile, myText);
        std::vector<std::string> ret = split(myText, ' ');
        edges.push_back({ret[0], ret[1], std::stoi(ret[2])});
    }
    // std::sort(edges.begin(), edges.end(), mycompare2);

    std::set<string> myset;
    std::map<string, map<string, int>> mymap;
    for (edge &aedge : edges)
    {
        myset.insert(aedge.startpoint);
        myset.insert(aedge.endpoint);
        if (!mymap.count(aedge.startpoint))
        {

            std::map<string, int> tmpmap = {{aedge.endpoint, aedge.value}};
            mymap.insert({aedge.startpoint, tmpmap});
        }
        else
        {
            mymap[aedge.startpoint].insert({aedge.endpoint, aedge.value});
        }
    }
    map<string, int> nodes;
    for (const auto &s : myset)
    {
        nodes.insert({s, INF});
    }


    getline(MyReadFile, startpoint);
    nodes[startpoint] = 0;


    while (!myset.empty())
    {
        /* code */
        myset.erase(startpoint);
        for (const auto &s : mymap[startpoint])
        {
            if (nodes[s.first] > nodes[startpoint] + s.second)
            {
                nodes[s.first] = nodes[startpoint] + s.second;
            }
        }
        int tmp = INF;
        for (const auto &s : myset)
        {
            if (tmp >= nodes[s])
            {
                tmp = nodes[s];
                startpoint = s;
            }
        }
    }
    // cout << endl;
    std::vector<std::pair<string, int>> my_vector(nodes.begin(), nodes.end());
    
    std::sort(my_vector.begin(), my_vector.end(), mycompare2);

    for (const auto &s : my_vector)
    {
        if(s.second==INF){
            break;
        }
        cout << s.first << " " << s.second << endl;
        outfile << s.first << " " << s.second << endl;
    }

    return 0;
}
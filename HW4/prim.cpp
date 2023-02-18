#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
#include "sp.h"
#include "edge.h"
#include <set>
#include <algorithm>


int main()
{
    string n_of_edge, myText, startpoint;
    string outf = "outp.txt";
    std::ofstream outfile;
    outfile.open(outf); // append instead of overwrite
    string infile = "sample_p.txt";
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



    std::sort(edges.begin(), edges.end(), mycompare);

    getline(MyReadFile, startpoint);
    std::set<string> myset;
    for (edge &aedge : edges)
    {
        if ((aedge.startpoint == startpoint) || (aedge.endpoint == startpoint))
        {
            cout<<aedge.startpoint<<" "<<aedge.endpoint<<" "<<aedge.value<<endl;
            outfile<<aedge.startpoint<<" "<<aedge.endpoint<<" "<<aedge.value<<endl;
            myset.insert(aedge.startpoint);
            myset.insert(aedge.endpoint);
            break;
        }
    }
    bool flag;
    
    while (true)
    {
        flag=false;
        for (edge &aedge : edges)
        {
            if (myset.count(aedge.startpoint) ^ myset.count(aedge.endpoint))
            {
                cout << aedge.startpoint << " "<< aedge.endpoint << " "<<aedge.value <<endl;
                outfile << aedge.startpoint << " "<< aedge.endpoint << " "<<aedge.value <<endl;
                myset.insert(aedge.startpoint);
                myset.insert(aedge.endpoint);
                flag=true;
                break;
            }
        }
        if(!flag){
            break;
        }
    }

    return 0;
}
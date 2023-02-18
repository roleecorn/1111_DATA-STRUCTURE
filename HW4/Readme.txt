using "g++ -std=c++11 dijkstra.cpp" and "g++ -std=c++11 prim.cpp" to compile
These code can complier on mac 12.6 and devc++

there are 2 .cpp files and 1 .h file in zip file
.
├── Readme.txt      this file 
├── edge.h          contain struct edge and compare two edges weight function
├── dijkstra.cpp    contain dijkstra function,
|                       using a map<string, map<string, int>> to show the nodes and those edges start from this node
├── prim.cpp        contain Prim’s algorithm
|                       using a set to check whether it cause a cycle (iff the new edge startpoint an endpoint in the set)
└── sp.h            contain the spilt string to a vector function
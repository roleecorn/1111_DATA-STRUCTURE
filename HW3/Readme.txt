using "g++ -std=c++11 main.cpp" to compile, these code can complier on mac 12.6
there are 1 .cpp file and 6 .h files in zip file
.
├── main.cpp    it is main file,contain the mode chooseing and make a rootnode 
|               please compile it
├── sp.h        contain the spilt string to a vector function
├── treenode.h  define the treenode struct
├── insert.h    contain the insert function 
├── search.h    contain the search function 
|                   before delete a node , delete.h also using it to check whether in tree
├── delete.h    contain the delete function 
|                   if target node has both right and left child, find succesor is the 
|                   smallest node in right tree
└── print.h     contain the print function 
                    print in four way ,prefix,infix ,postfix ,level order:
main.cpp can change the parameter to select input file and outfile name
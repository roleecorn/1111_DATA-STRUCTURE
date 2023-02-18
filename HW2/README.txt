using "g++ -std=c++17 main.cpp" to compile, these code can complier on mac 12.6
there are 1 .cpp file and 1 .h files in rar file
    main.cpp --it is main file,please compile it
                contain the code let maze file reading to a vector<vector<char>> martrix
                if there can't match the maze file it will print "not a file" and return 
    DFS.h    --it is method to do DFS of sloving the maze problem
                The detailed method is written in the comments
                using stack to record every choosen and go forward until there isn't any legal move
                then pop out the top of the stack, it means backford
main.cpp can change the parameter to select input file and outfile name
outfile name is default as h2.out
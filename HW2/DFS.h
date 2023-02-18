#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance, string outf)
    {
        std::ofstream outfile;
        outfile.open(outf, std::ios_base::app); // append instead of overwrite
        // a tuple Items to get the top of stacks
        tuple<int, int, int> Items;
        int row = maze.size();
        int col = maze[0].size();
        // mark to check whether it have comes
        int mark[17][17] = {0};
        // stack to record evert next choosen
        stack<tuple<int, int, int>> st;
        // push the first select
        st.push({entrance[0], entrance[1], 0});
        mark[entrance[0]][entrance[1]] = 1;
        // direc chosen in order
        int direction[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        // step counter
        int cnt = -1;

        while (!st.empty())
        {
            Items = st.top();
            st.pop();
            int d = get<2>(Items);
            int x = get<0>(Items);
            int y = get<1>(Items);

            cnt++;
            outfile << cnt << ":" << x << "," << y << endl;
            cout << cnt << ":" << x << "," << y << endl;
            // success exit in maze[15][16]
            if ((x == 15) && (y == 16))
            {
                cout << "find out" << endl;
                outfile << "find out" << endl;
                return 0;
            }
            // try the direct from 0 to 7
            while (d < 8)
            {
                int g, h;
                //calculate what position is next step
                g = x + direction[d][0];
                h = y + direction[d][1];
                if (g < 0 || h < 0 || g > 16 || h > 16)
                {
                    d++;
                    continue;
                }
                // if it is a OK position, go forward and push next selection to stack
                if (maze[g][h] == '0' && mark[g][h] == 0)
                {
                    mark[g][h] = 1;
                    cnt++;
                    outfile << cnt << ":" << g << "," << h << endl;
                    cout << cnt << ":" << g << "," << h << endl;
                    if ((g == 15) && (h == 16))
                    {
                        cout << "successfully escaped!!" << endl;
                        outfile << "successfully escaped!!" << endl;
                        return 0;
                    }
                    // push next direct of this position
                    st.push({x, y, d + 1});
                    // now try next position, start from go East
                    x = g;
                    y = h;
                    d = 0;
                }
                // or try next direction
                else
                {
                    d++;
                }
            }
        }
        outfile << "fail to escape" << endl;
        return 0;
    }
};
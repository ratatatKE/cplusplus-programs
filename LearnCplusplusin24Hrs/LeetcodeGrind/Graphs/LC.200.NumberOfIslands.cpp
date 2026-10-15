#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        /*
         Go through the list checking which nodes are unreachable.
         Keep track of the number of those islands.
        Input: grid =
         [      0   1   2   3   4
            0 ["1","1","1","1","0"],
            1 ["1","1","0","1","0"],
            2 ["1","1","0","0","0"],
            3 ["0","0","0","0","0"]
        ]
        Output: 1

         Create an adjacency list for input matrix
         0->0,1,2,3
         1->0,1,3
         2->0,1
         3->

        */

        int rows = grid.size();    // 4
        int cols = grid[0].size(); // 5
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                // for each row and column in the grid.
                if (grid[r][c] == '1' && visited[r][c] == false)
                {
                    islands++;
                    bfsMatrix(grid, r, c, visited, directions, rows, cols);
                }
            }
        }
        return islands;
    }

    void bfsMatrix(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &visited, vector<pair<int, int>> &directions, int rows, int cols)
    {
        // the queue in BFS or stack in DFS stores the pair
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (auto [direction_row, direction_col] : directions)
            {
                int new_row = row + direction_row;
                int new_column = col + direction_col;

                // Check before adding it into the queue. Remember we mark visited when we push to queue
                if (new_row >= 0 && new_row < rows && new_column >= 0 && new_column < cols && grid[new_row][new_column] == '1' && !visited[new_row][new_column])
                {
                    q.push({new_row, new_column});
                    visited[new_row][new_column] = true;
                }
            }
        }
    }
};

int main()
{

    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    Solution sol;
    cout << "result from program is " << sol.numIslands(grid2) << endl;
}

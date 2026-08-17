/*
https://chatgpt.com/g/g-p-6a194dcabbec819190679991397c8270/c/6a5f536e-51c8-83ea-9027-555d12279835

GPT:
One small improvement I made compared to Abdul Bari's
original code is that I converted the graph to 0-based indexing,
since virtually all modern C++ libraries, LeetCode problems,
and STL containers use 0-based indices.
This makes the code feel much more natural for interview practice.

So instead of using the below:

            1
          /   \
         2     3
          \   /
            4
           / \
          5   6

    int G[7][7] =
    {
        // 0  1  2  3  4  5  6
        {0, 0, 0, 0, 0, 0, 0}, // 0 (unused)

        {0, 0, 1, 1, 0, 0, 0}, // 1
        {0, 1, 0, 0, 1, 0, 0}, // 2
        {0, 1, 0, 0, 1, 0, 0}, // 3
        {0, 0, 1, 1, 0, 1, 1}, // 4
        {0, 0, 0, 0, 1, 0, 0}, // 5
        {0, 0, 0, 0, 1, 0, 0}  // 6
    };

Edges:
1 -- 2
1 -- 3
2 -- 4
3 -- 4
4 -- 5
4 -- 6



We instead use the below:
--------------------------------------------------
 Abdul Bari Graph (0-based version)

      0
    /   \
   1     2
    \   /
      3
     / \
    4   5
--------------------------------------------------

Which translates to:
vector<vector<int>> matrix =
        {
          // 0  1  2  3  4  5
            {0, 1, 1, 0, 0, 0},  //0
            {1, 0, 0, 1, 0, 0},  //1
            {1, 0, 0, 1, 0, 0},  //2
            {0, 1, 1, 0, 1, 1},  //3
            {0, 0, 0, 1, 0, 0},  //4
            {0, 0, 0, 1, 0, 0}}; //5

Edges:
0 -- 1
0 -- 2
1 -- 0
1 -- 3
2 -- 0
2 -- 3
3 -- 1
3 -- 2
3 -- 4
3 -- 5
4 -- 3
5 -- 3


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> matrixToList(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> graph(n); // graph with n number of elements uninitialized.

    for (int node = 0; node < n; node++)
    {
        for (int neighbour = 0; neighbour < n; neighbour++)
        {
            if (matrix[node][neighbour])
            {
                graph[node].push_back(neighbour);
            }
        }
    }
    return graph;
}

void printList(const vector<vector<int>> &graph)
{
    cout << "Adjacency list \n";

    for (int node = 0; node < graph.size(); node++)
    {
        cout << node << " -> ";

        for (int neighbour : graph[node])
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

vector<int> bfsMatrix(const vector<vector<int>> &matrix, int start)
{
    int n = matrix.size();

    vector<bool> visited(n, false);
    vector<int> order;
    queue<int> q;

    q.push(start);
    visited[start] = true;
}











int main()
{
    vector<vector<int>> matrix =
        {
            {0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 1, 1, 0, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0}};

    vector<vector<int>> graph = matrixToList(matrix);
    printList(graph);
}
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

/*
    Helper functions
*/
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

void printTraversal(const string &title, const vector<int> &result)
{
    cout << title << " : ";
    for (int node : result)
    {
        cout << node << " ";
    }

    cout << '\n';
}

/*
    Matrix BFS
*/

vector<int> bfsMatrix(const vector<vector<int>> &matrix, int start)
{
    int n = matrix.size();

    vector<bool> visited(n, false);
    vector<int> result;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        result.push_back(node);

        for (int neighbour = 0; neighbour < n; neighbour++)
        {
            if (matrix[node][neighbour] && !visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return result;
}

/*
    Matrix DFS
*/

void dfsMatrixHelper(const vector<vector<int>> &matrix, int node, vector<bool> &visited, vector<int> &result)
{
    visited[node] = true;
    result.push_back(node);

    for (int neighbour = 0; neighbour < matrix.size(); neighbour++)
    {
        if (matrix[node][neighbour] && !visited[neighbour])
        {
            dfsMatrixHelper(matrix, neighbour, visited, result);
        }
    }
}

vector<int> dfsMatrix(const vector<vector<int>> &matrix, int start)
{
    vector<bool> visited(matrix.size(), false);
    vector<int> result;

    dfsMatrixHelper(matrix, start, visited, result);
    return result;
}

/*
    Adjacency List BFS
*/

vector<int> bfsList(const vector<vector<int>> &graph, int start)
{
    vector<bool> visited(graph.size(), false);
    vector<int> result;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        result.push_back(node);

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return result;
}

/*
    Adjacency List DFS
*/

void dfsListHelper(const vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &result)
{
    visited[node] = true;
    result.push_back(node);

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            dfsListHelper(graph, neighbour, visited, result);
        }
    }
}

vector<int> dfsList(const vector<vector<int>> &graph, int start)
{
    vector<bool> visited(graph.size(), false);
    vector<int> result;

    dfsListHelper(graph, start, visited, result);

    return result;
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

    int start = 0;

    printTraversal("BFS Matrix", bfsMatrix(matrix, start));
    printTraversal("DFS Matrix", dfsMatrix(matrix, start));
    printTraversal("BFS List", bfsList(graph, start));
    printTraversal("DFS List", dfsList(graph, start));

    /*
            
    Output:
    Adjacency list 
    0 -> 1 2 
    1 -> 0 3 
    2 -> 0 3 
    3 -> 1 2 4 5 
    4 -> 3 
    5 -> 3 

    BFS Matrix : 0 1 2 3 4 5 
    DFS Matrix : 0 1 3 2 4 5 
    BFS List : 0 1 2 3 4 5 
    DFS List : 0 1 3 2 4 5 
    
    Note:  0 1 3 4 5 2 and 0 1 3 5 4 2 are also valid DFS traversals. But this program is deterministic. It always checks neighbors in increasing order 0,1,2,3,4,5 with the line `for (int neighbor = 0; neighbor < n; neighbor++)` hence the results.
    
    */

    return 0;
}
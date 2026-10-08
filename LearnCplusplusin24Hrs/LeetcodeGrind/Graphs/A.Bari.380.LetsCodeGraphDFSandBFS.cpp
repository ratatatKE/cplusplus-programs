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
#include <stack>

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

    Special note about matrix.size():
    If matrix was a C 2D style array i.e. `int matrix[6][6];`, then there's no .size() at all, sizeof(matrix)/sizeof(int) = 36.
    However this is C++, matrix is not a 6*6 block of ints. matrix is a vector<<vector<int>>, think of it like `matrix = [ row0, row1, row2, row3, row4, row5 ]`. 
    That's 6 things, each of those things itself is a vector of 6 ints. That's why matrix.size()=6 for the below matrix.

    input ==  vector<vector<int>> matrix =
        {
            {0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 1, 1, 0, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0}};

    To learn what `if(matrix[node][neighbour]) does, see GDB output based on our current input:
    +p (bool)(matrix[0][0])
    $9 = false
    +p (bool)(matrix[0][1])
    $10 = true
    +p (bool)(matrix[0][2])
    $11 = true
    +p (bool)(matrix[0][3])
    $12 = false
    +p (bool)(matrix[0][4])
    $13 = false
    +p (bool)(matrix[0][5])
    $14 = false

    // Here at [0][6] and [0][7] we are reading memory that is not ours and out of bounds of our matrix hence the GARBAGE.
    +p (bool)(matrix[0][6])
    $15 = true
    +p (bool)(matrix[0][7])
    $16 = false

*/

vector<int> bfsMatrix(const vector<vector<int>> &matrix, int start)
{
    int n = matrix.size(); // n=6

    vector<bool> visited(n, false); // visited={false, false, false, false, false, false}
    vector<int> result;             // result={}
    queue<int> q;                   // q={}

    visited[start] = true; // visited{true,...}
    q.push(start);         // q={0}  NOTE: Left is front, right is back

    while (!q.empty()) // q={0}, visited{true,...} | q={1,2} visited{true,true,true,...} | q={2,3} visited={true, true, true, true,....} |  q={3} visited={true, true, true, true,....}; |  q={4,5} visited={true, true, true, true, true, true} | q={5} visited={true, true, true, true, true, true} | Xwhile() result={0,1,2,3,4,5}
    {
        int node = q.front(); // node=0 | node=1 | node=2 | node=3 | node=4 | node=5
        q.pop();              // q={}   | q={2}  | q={3}  | q={ }  | q{5}   | q={ }

        result.push_back(node); // result={0} | result={0,1} | result={0,1,2} | result={0,1,2,3} | result={0,1,2,3,4} | result={0,1,2,3,4,5}

        for (int neighbour = 0; neighbour < n; neighbour++)
        // for( neighbour=0, neighbour< 6, ++),visited{true,...} ; for(int neighbour=1, neighbour< 6; ++), visited{true,...} ; for(int neighbour=2, neighbour< 6; ++), visited{true,true,...} ;                                                                                                                                 \
        // for(int neighbour=3, neighbour< 6, ++), visited{true,true,true,...} ; for(int neighbour=4, neighbour< 6; ++),  visited{true,true,true,...} ;                                                                                                                                                                         \
        // for(int neighbour=5, neighbour< 6, ++),  visited{true,true,true,...} ; Xfor() with  visited{true,true,true,...} q={1,2}                                                                                                                                                                                              |
        // for(neighbour=0, neighbour< 6, ++), visited{true,true,true,...} ; for( neighbour=1, neighbour< 6, ++), visited{true,true,true,...} ; for( neighbour=2, neighbour< 6, ++), visited{true,true,true,...}                                                                                                                \
        // for(neighbour=3, neighbour< 6, ++), visited{true,true,true,...} ;  for( neighbour=4, neighbour< 6, ++), visited={true, true, true, true,....} ; for( neighbour=5, neighbour< 6, ++), visited={true, true, true, true,....}; Xfor() with visited={true, true, true, true,....}  q={2.3}                               |
        // for(neighbour=0, neighbour<6, ++), visited={true, true, true, true,....} ; for( neighbour=1, neighbour<6, ++), visited={true, true, true, true,....} ; for( neighbour=2, neighbour<6, ++), visited={true, true, true, true,....}                                                                                     \
        // for(neighbour=3, neighbour<6, ++), visited={true, true, true, true,....} ; for( neighbour=4, neighbour<6, ++), visited={true, true, true, true,....} ; for( neighbour=5, neighbour<6, ++), visited={true, true, true, true,....}; xfor() with visited={true, true, true, true,....} q={3}                            |
        // for(neighbour=0, neighbour<6, ++), visited={true, true, true, true,....} ; for(neighbour=1, neighbour<6, ++), visited={true, true, true, true,....} ; for(neighbour=2, neighbour<6, ++), visited={true, true, true, true,....}                                                                                       \
        // for(neighbour=3, neighbour<6, ++), visited={true, true, true, true,....} ; for(neighbour=4, neighbour<6, ++), visited={true, true, true, true,....} ; for(neighbour=5, neighbour<6, ++), visited={true, true, true, true, true....} ; xfor() with visited={true, true, true, true, true, true} q={4,5}               |
        // for(neighbour=0, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=1, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=2, neighbour<6, ++), visited={true, true, true, true, true, true}                                                                    \
        // for(neighbour=3, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=4, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=5, neighbour<6, ++), visited={true, true, true, true, true, true}; xfor() with visited={true, true, true, true, true, true} q{5}     |
        // for(neighbour=0, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=1, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=2, neighbour<6, ++), visited={true, true, true, true, true, true};                                                                   \
        // for(neighbour=3, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=4, neighbour<6, ++), visited={true, true, true, true, true, true}; for(neighbour=5, neighbour<6, ++), visited={true, true, true, true, true, true}; xfor() with visited={true, true, true, true, true, true} q{ } 
        {
            if (matrix[node][neighbour] && !visited[neighbour])
            // if(matrix[0][0] i.e. false && !visited[0]) ; if(matrix[0][1] i.e. true && !visited[1]) ; if(matrix[0][2] i.e. true && !visited[2]) ; if(matrix[0][3] i.e. false && !visited[3]) ; if(matrix[0][4] i.e. false && !visited[4]) ; if(matrix[0][5] i.e. false && !visited[5])    |
            // if(matrix[1][0] i.e. true  && !visited[0]) ; if(matrix[1][1] i.e. false && !visited[1]) ; if(matrix[1][2] i.e. false && !visited[2]) ; if(matrix[1][3] i.e. true && !visited[3]) ; if(matrix[1][4] i.e. false && !visited[4]) ; if(matrix[1][5] i.e. false && !visited[5])   |
            // if(matrix[2][0] i.e. true && !visited[0]) ; if(matrix[2][1] i.e. false && !visited[1]) ; if(matrix[2][2] i.e. false && !visited[2]) ; if(matrix[2][3] i.e. true && !visited[3]) ; if(matrix[2][4] i.e. false && !visited[4]) ;  if(matrix[2][5] i.e. false && !visited[5])   |
            // if(matrix[3][0] i.e. false && !visited[0]);  if(matrix[3][1] i.e. true && !visited[1]); if(matrix[3][2] i.e. true && !visited[2])  ; if(matrix[3][3] i.e. false && !visited[3]) ; if(matrix[3][4] i.e. true && !visited[4]) ; if(matrix[3][5] i.e. true && !visited[5])      |
            // if(matrix[4][0] i.e. false && !visited[0]); if(matrix[4][1] i.e. false && !visited[1]); if(matrix[4][2] i.e. false && !visited[2]) ; if(matrix[4][3] i.e. true && !visited[3]) ; if(matrix[4][4] i.e. false && !visited[4]) ; if(matrix[4][5] i.e. false && !visited[5])     |
            // if(matrix[5][0] i.e. false && !visited[0]); if(matrix[5][1] i.e. false && !visited[1]); if(matrix[5][2] i.e. false && !visited[2]) ; if(matrix[5][3] i.e. true && !visited[3]) ; if(matrix[5][4] i.e. false && !visited[4]) ; if(matrix[5][5] i.e. false && !visited[5])
            {
                visited[neighbour] = true; 
                // -; visited={true,true,...}; visited={true,true,true,...} ; - ; - ; - ;                                   |
                // -; -; -; visited={true, true, true, true,....} ; -; -;                                                   |
                // -; -; -; -; -; -;                                                                                        |
                // -; -; -; -; visited={true, true, true, true, true....} ; visited={true, true, true, true, true, true}    |
                // -; -; -; -; -; -;                                                                                        |
                // -; -; -; -; -; -;
                q.push(neighbour);         
                // -; q={1} ; q={1,2} ; - ; - ; -;                                                                          |
                // -; -; -; q={2,3} ; -; -;                                                                                 |
                // -; -; -; -; -; -;                                                                                        |
                // -; -; -; -; q={4}; q={4,5}                                                                               |
                // -; -; -; -; -; -;                                                                                        |
                // -; -; -; -; -; -;
            }
        }
    }

    return result; //...... result={0,1,2,3,4,5}
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
    Adjacency List BFS. CORRECT ANNOTATION 24082026

    input = &graph
    0 -> 1 2
    1 -> 0 3
    2 -> 0 3
    3 -> 1 2 4 5
    4 -> 3
    5 -> 3
*/

vector<int> bfsList(const vector<vector<int>> &graph, int start) // bfsList(&graph, start=0)
{
    vector<bool> visited(graph.size(), false); // visited={false,false,false,false,false,false}
    vector<int> result;                        // result={}
    queue<int> q;                              // q={}

    visited[start] = true; // visited={true,false,false,false,false,false}
    q.push(start);         // q={0}

    while (!q.empty()) // q={0} | q={1,2} | q={2,3} | q={3} | q={4,5} | q=5 | q={} XWhile()
    {
        int node = q.front(); // node=0 | node=1 | node=2 | node=3 | node=4 | node=5
        q.pop();              // q={} | q={2} | q={3} | q={} | q={5} | q={}

        result.push_back(node); // result={0,} | result={0,1} | result={0,1,2} | result={0,1,2,3} | result={0,1,2,3,4} | result={0,1,2,3,4,5}

        for (int neighbour : graph[node]) // for( : 1 2)  | for( : 0 3) | for( : 0 3) | for( : 1 2 4 5) | for( : 3) | for( : 3)
        {
            if (!visited[neighbour])
            // visited={true,...}, visited[1]==false; visited={true,true,...}, visited[2]==false |
            // visited={true,true,true...}, visited[0]==true; visited={true,true,true...}, visited[3] == false |
            // visted={true,true,true,true,..}, visited[0]=true; visited={true,true,true,true,..}, visited[3]=true |
            // visited={true,true,true,true,..}, visited[1]=true; visited={true,true,true,true,..}, visited[2]=true; visited={true,true,true,true,..}, visited[4]=false; visited={true,true,true,true,true..}, visited[5]=false |
            // visited={true,true,true,true,true,true..}, visited[3]=true; |
            // visited={true,true,true,true,true,true..}, visited[3]=true;
            {
                visited[neighbour] = true; // visited={true,true,...}; visited={true,true,true,...}; | -; visted={true,true,true,true,..} | -; -; | -; -; visited={true,true,true,true,true..} ; visited={true,true,true,true,true, true..} | -; | -;
                q.push(neighbour);         // q={1}; q={1,2} | -; q={2,3} | -; -; | -; -; q={4}; q={4,5} | -; | -;
            }
        }
    }

    return result; // -; | -; | -; | -; | -; | -; | result={0,1,2,3,4,5}
}

/*
    Adjacency List DFS. CORRECT ANNOTATION 24082026

    input = &graph
    0 -> 1 2
    1 -> 0 3
    2 -> 0 3
    3 -> 1 2 4 5
    4 -> 3
    5 -> 3
*/

void dfsListHelper(const vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &result)
// dfsListHelper(&graph, 0, &visited, &result)                                  |
// dfsListHelper(&graph, 1, visited={true,....}, result={0})  o=>1;             ||
// dfsListHelper(&graph, 3, visited={true,true,true,...}, o=>3)                 |||
// dfsListHelper(&graph, 2, visited={true,true,false,true,...}) o=>2            ||||
// dfsListHelper(&graph, 4, visited={true,true,true,true,....}) o=>4            |||||
// dfsListHelper(&graph, 5, visited={true,true,true,true,true....}) o=>5        ||||||

{
    visited[node] = true;
    // visited={true,....}                          |
    // visited={true,true,....}                     ||
    // visited={true,true,false,true,...}           |||
    // visited={true,true,true,true,...}            ||||
    // visited={true,true,true,true,true...}        |||||
    // visited={true,true,true,true,true, true}     ||||||

    result.push_back(node);
    // result={0}                   |
    // result={0,1}                 ||
    // result={0,1,3}               |||
    // result={0,1,3,2}             ||||
    // result={0,1,3,2,4}           |||||
    // result={0,1,3,2,4,5}         ||||||

    for (int neighbour : graph[node])
    // for( : 1 2)                  |
    // for( : 0 3); for( :0 3)      ||
    // for( : 1 2 4 5)              |||
    // for( : 0 3)                  ||||
    // for( : 3)                    |||||
    // for( : 3)                    ||||||
    {
        if (!visited[neighbour])
        // visited[1]=false; visited[2]=true     xEnddfsListHelper()    |
        // visited[1]=true; visited[3] =false                           ||
        // visited[1]=true; visited[2]=false; visited[4]=false;         |||
        // visited[0]=true; visited[3]=true;                            ||||
        // visited[3] = true;                                           |||||
        // visited[3] = true;                                           ||||||
        {
            dfsListHelper(graph, neighbour, visited, result);
            // dfsListHelper(&graph, 1, visited={true,....}, result={0})  o=>1 1<=o xReturnedfromII; -; |
            // -; dfsListHelper(&graph, 3, visited={true,true,true,...}), o=>3 o=<3 xReturnedFromIII; ||
            // -; dfsListHelper(&graph, 2, visited={true,true,false,true,...}) o=>2 2<=o xreturnedfromIIII; dfsListHelper(&graph, 4, visited={true,true,true,true,...}) o=>4 o=<4 xReturnedfromIIIII; dfsListHelper(&graph, 5, visited={true,true,true,true,true,....}) o=>5 o=<5 xReturnedfromIIIIII |||
            // -; -; ||||
            // -;    |||||
            // -;    ||||||
        }
    }
}

vector<int> dfsList(const vector<vector<int>> &graph, int start)
{
    vector<bool> visited(graph.size(), false);
    vector<int> result;

    dfsListHelper(graph, start, visited, result); // dfsListHelper(&graph, 0, &visited, &result)

    return result;
}

/*
    Still traversing DFS in our Adjacency list but this time using an explicit stack.

    input = &graph
    0 -> 1 2
    1 -> 0 3
    2 -> 0 3
    3 -> 1 2 4 5
    4 -> 3
    5 -> 3
*/

vector<int> dfsListButStackBased(const vector<vector<int>> &graph, int start) // dfsListButStackBased(graph, 0)
{
    vector<bool> visited(graph.size(), false); // visited={false,  false, false, false, false, false}
    vector<int> result;                        // result={}

    stack<int> st; // st={} (NOTE: left right is the top of the stack, left is the bottom)

    visited[start] = true; // visited={true, false, false, false, false, false}
    st.push(start);        // st={0}

    while (!st.empty()) // st={0} |  st={1,2} | st={1,3} | st={1,4,5} | st={1,4} | st={1} | st={} Xwhile() with result={0,2,3,5,4,1}
    {
        int node = st.top(); // node=0 | node=2  | node=3 | node=5 | node=4 | node=1
        st.pop();            // st={} | st={1} | st={1} | st={1, 4} | st={1} | st={}

        result.push_back(node); // result={0} | result={0,2} | result={0,2,3} | result={0,2,3,5} | result={0,2,3,5,4} | result={0,2,3,5,4,1}

        for (int neighbour : graph[node]) // for( : 1 2) | for(: 0 3) | for( : 1 2 4 5) | for(: 3) | for (: 3) | for( : 0 3)
        {
            if (!visited[neighbour])
            // visited[1]==false ; visited[2]==false | visited[0]==true; visited[3]==false  |
            // visited[1]==true; visited[1]==true; visited[4]==false;  visited[5]==false    |
            // visited[3]==true;                                                            |
            // visited[3]==true;                                                            |
            // visited[0]==true; visited[3]==true
            {
                visited[neighbour] = true;
                // visited={true, true, false, false, false, false} ; visited={true, true, true, false, false, false} | -; visited={true, true, true, true, false, false}   |
                // -; -; visited={true, true, true, true, true, false}; visited={true, true, true, true, true, true}                                                        |
                // -;                                                                                                                                                       |
                // -:                                                                                                                                                       |
                // -; -;
                st.push(neighbour);
                // st={1} ; st={1,2} | st={1}; st{1,3}      |
                // st={1}; st={1}; st={1,4}; st={1,4,5}     |
                // st={1, 4};                               |
                // st={1};                                  |
                // st={}; st={}
            }
        }
    }

    // return result
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

    cout << "NdedaC: matrix 3,0 = " << matrix[3][0] << " matrix[3][1] =" << matrix[3][1] << " matrix[3][2] =" << matrix[3][2] << " matrix 3,3 =" << matrix[3][3] << " matrix3,4 = " << matrix[3][4] << " and matrix 3,5 =" << matrix[3][5] << std::endl;

    vector<vector<int>> graph = matrixToList(matrix);
    printList(graph);

    int start = 0;

    printTraversal("BFS Matrix", bfsMatrix(matrix, start));
    printTraversal("DFS Matrix", dfsMatrix(matrix, start));
    printTraversal("BFS List", bfsList(graph, start));
    printTraversal("DFS List", dfsList(graph, start));
    printTraversal("DFS List But Using Explicit Stack: ", dfsListButStackBased(graph, start));

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
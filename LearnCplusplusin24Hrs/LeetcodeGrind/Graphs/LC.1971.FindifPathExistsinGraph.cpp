#include <iostream>
#include <vector>

class Solution
{
public:
    bool validPath(int n, std::vector<std::vector<int>> &edges, int source,
                   int destination)
    {
        /*
            1. Create an adjacency list.
            2. then given a source and a destination, start a DFS to see if we
           can get to that destination. DFS always needs a helper coz stack and recursion.
        */

        std::vector<std::vector<int>> alist(n);
        createalist(alist, edges);

        return find(alist, source, destination);
    }

    bool find(std::vector<std::vector<int>> &graph, int source, int destination)
    {
        bool result = false;

        for (int neighbour : graph[source])
        {
            {
                if (neighbour == destination)
                {
                    result = true;
                }
            }
        }

        return result;
    }

    void createalist(std::vector<std::vector<int>> &alist, std::vector<std::vector<int>> &edges)
    {
        for (int i = 0; i < alist.size(); i++)
        { // i=0, i<3
            for (std::vector<int> x : edges)
            { //
                if (i == x[0])
                {
                    alist[i].push_back(x[1]);
                    // graph is non-directed so push_back both ways
                    alist[x[1]].push_back(i);
                }
            }
        }
    }
};

int main()
{
    int n = 3;
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0;
    int destination = 2;

    Solution sol;
    std::cout << "result: " << sol.validPath(n, edges, source, destination) << std::endl;
}
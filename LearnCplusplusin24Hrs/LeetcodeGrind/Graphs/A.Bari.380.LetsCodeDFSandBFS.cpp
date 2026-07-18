/*
Below is the Graph  we will use:

            1
          /   \
         2     3
          \   /
            4
           / \
          5   6

Edges:
1 -- 2
1 -- 3
2 -- 4
3 -- 4
4 -- 5
4 -- 6
*/

int main()
{

    /*
        Using a 7 × 7 adjacency matrix with row/column 0 left unused is a very common convention
        in textbooks (such as Abdul Bari's lectures) because the vertex numbers start at 1,
        making the matrix indices match the vertex labels exactly.
    */
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

    return 0;
}


void BFS(int G[][7], int start, int no_of_nodes){
    
}

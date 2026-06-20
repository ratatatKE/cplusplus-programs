#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    /*  
    So when you do new TreeNode(), it creates a node with val = 0, left = nullptr, right = nullptr.
    You could write it like this instead:
        TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
        }
    
    But the initializer list is preferred because:

    - Const members and references MUST be initialized there. You can't assign to them in the body.
    - Efficiency: With the body version, members are default-constructed first, then assigned. With the initializer list, 
        they’re constructed once with the right value.
    - For pointers/primitives it doesn't matter much, but for class-type members it's faster.
    */
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { // [1,null,2,3]
        vector<int> list;
        inorder(root, list); 
        // Solution::inorder (this=0x7fffffffd9fb, root=0x55555556d2b0, result=std::vector of length 0, capacity 0) ||||| \
        // Solution::inorderTraversal (this=0x7fffffffd9fb, root=0x55555556d2b0); result = std::vector of length 3, capacity 4 = {1, 3, 2} ,*root = {  val = 1,  left = 0x0,  right = 0x55555556d2d0 }
        return list;
    }

    void inorder(TreeNode* root, vector<int>& result) { 
    // Solution::inorder (this=0x7fffffffd9fb, root=0x55555556d2b0, result=std::vector of length 0, capacity 0)     o=> 1                                           || \
    // Solution::inorder (this=0x7fffffffd9fb, root=0x0, result=std::vector of length 0, capacity 0)                o=> 1->left/null/0x00 o=<  1->left/null/0x00    ||| \
    // Solution::inorder (this=0x7fffffffd9fb, root=0x55555556d2d0, result=std::vector of length 1, capacity 1 = {...})       o=> 1->right                          |||| \
    // Solution::inorder (this=0x7fffffffd9fb, root=0x55555556d2f0, result=std::vector of length 1, capacity 1 = {...})       o=> 2->left                           ||||| \
    // Solution::inorder (this=0x7fffffffd9fb, root=0x0, result=std::vector of length 1, capacity 1 = {...})        o=> 3->left/null/0x00                           |||||| \ 
    // Solution::inorder (this=0x7fffffffd9fb, root=0x0, result=std::vector of length 2, capacity 2 = {...})        o=> 3->right/null/0x00                          ||||||| \
    // Solution::inorder (this=0x7fffffffd9fb, root=0x0, result=std::vector of length 3, capacity 4 = {...})        o=> 2->right/null/0x00                          |||||||| \
        /*
                1
                 \
                  2
                 /
                3
        /*/

        // inorder([1,null,2,3]), result) =o> 1                                                                             || \
        // inorder(1->left i.e. NULL), result) =o> 1-left/null/0x00                                                         ||| \
        // inorder(1->right], result{1,}) o=> 1->right                                                                      |||| \
        // inorder(2->left], result{1,}) o=>  2->left                                                                       ||||| \
        // inorder(3->left i.e. NULL], result{1,}) o=>  3->left/null/0x00                                                   |||||| \
        // inorder(3->right i.e. NULL], result{1, 3,}) o=>  3->right/null/0x00                                              ||||||| \
        // inorder(2->right i.e. NULL], result{1, 3, 2}) o=>  2->right/null/0x00                                            |||||||| \         


        if (root == NULL) {         
        //if addrof1==NULL      =o> 1                                                                                       || \
        //if 0x00==NULL         o=> 1->left/null/0x00                                                                       ||| \
        //if 1->right==NULL     o=> 1->right                                                                                |||| \
        //if 2->left==NULL      o=> 2->left                                                                                 ||||| \
        //if 3->left i.e. 0x00==NULL      o=> 3->left                                                                       |||||| \
        //if 3->right i.e. 0x00==NULL     o=> 3->right                                                                      ||||||| \
        //if 2->right i.e. 0x00==NULL     o=> 2->right                                                                      |||||||| \


            return;                                                     
            // - o=>1;                                                                                                      || \
            // xif{}returned =o< 1->left/null/0x00                                                                          ||| \
            // - o=>1->right;                                                                                               |||| \
            // - o=>2->left;                                                                                                ||||| \
            // xif{}returned =o< 3->left/null/0x00                                                                          |||||| \
            // xif{}returned =o< 3->right/null/0x00                                                                         ||||||| \
            // xif{}returned =o< 2->right/null/0x00      o=< 2->right@|||||RECcall                                          |||||||| \                                  
        }       

        inorder(root->left, result);        
        // inorder(1->left i.e. NULL, result), result) =o>1  o=<  1->left/null/0x00                                         || \
        /*        *root = {            val = 2,            left = 0x55555556d2f0,            right = 0x0        }        */
        // inorder(2->left, result)  o=> 2->left  o=< 2->left from @|||||RECcall                                            |||| \
        // inorder(3->left i.e. NULL, result)  o=> 3->left   =o< 3->left/null/0x00                                          ||||| \

        result.push_back(root->val);        
        // result={1}     o=>1                                                                                              || \
        // result={1,3}   o=>3                                                                                              ||||| \
        // result={1,3,2}  o=>2                                                                                            


        inorder(root->right, result); 
    /*            *root = {                val = 1,                left = 0x00,                right = 0x55555556d2d0            }        */
    // Solution::inorder (this=0x7fffffffd9fb, root=0x55555556d2d0, result=std::vector of length 1, capacity 1 = {...})  o=> 1->right   o=< 1->right from @|||||RECcall, Xinorder() then exited     || \  
    /* root = {                    val = 3,                    left = 0x0,                    right = 0x0                        } */
    // Solution::inorder (this=0x7fffffffd9fb, root=0x0, result=std::vector of length 2, capacity 2 = {...})  o=> 3->right o=< 3->right o=< 2->left @||||RECcall                                    ||||| \
    /* root = {  val = 2,  left = 0x55555556d2f0,  right = 0x0 */
    // Solution::inorder (this=0x7fffffffd9fb, root=0x0, result=std::vector of length 3, capacity 4 = {...})  o=> 2->right o=< 2->right from @||||||||RECcall o=<1->right@||RECcall                 |||| 

    }
};


int main()
{
    /************************************************
        Test Case 1

                1
                 \
                  2
                 /
                3

        LeetCode:
        [1,null,2,3]
        // stopped at 287. Lets Code Binary Tree in C++
        Notice Array Representation of a tree: (covered in 276. Representation of a Binary Tree by Abdul Bari) : https://docs.google.com/document/d/1reGl-41e-hTLLaR6vZxwcQXGejQk_IfuvhumajJZXfg/edit?tab=t.4cuj1vmhzsc2



    ************************************************/

    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);

    Solution sol;

    vector<int> ans1 = sol.inorderTraversal(root1);

    cout << "Test Case 1: ";

    for(int x : ans1)
        cout << x << " ";

    cout << endl;


    /************************************************
        Test Case 2

                    1
                  /   \
                 2     3
                / \     \
               4   5     8
                  / \   /
                 6   7 9

        LeetCode:
        [1,2,3,4,5,null,8,null,null,6,7,9]
    ************************************************/

    // TreeNode* root2 = new TreeNode(1);

    // root2->left = new TreeNode(2);
    // root2->right = new TreeNode(3);

    // root2->left->left = new TreeNode(4);
    // root2->left->right = new TreeNode(5);

    // root2->left->right->left = new TreeNode(6);
    // root2->left->right->right = new TreeNode(7);

    // root2->right->right = new TreeNode(8);
    // root2->right->right->left = new TreeNode(9);

    // vector<int> ans2 = sol.inorderTraversal(root2);

    // cout << "Test Case 2: ";

    // for(int x : ans2)
    //     cout << x << " ";

    // cout << endl;

    return 0;
}
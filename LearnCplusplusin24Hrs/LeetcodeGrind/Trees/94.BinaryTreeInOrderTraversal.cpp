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
    - Efficiency: With the body version, members are default-constructed first, then assigned. With the initializer list, they’re constructed once with the right value.
    - For pointers/primitives it doesn't matter much, but for class-type members it's faster.
    */
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> list;
        inorder(root, list);
        return list;
    }

    void inorder(TreeNode* root, vector<int>& result)
    {
        if(root == NULL)
            return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
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

    TreeNode* root2 = new TreeNode(1);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    root2->left->right->left = new TreeNode(6);
    root2->left->right->right = new TreeNode(7);

    root2->right->right = new TreeNode(8);
    root2->right->right->left = new TreeNode(9);

    vector<int> ans2 = sol.inorderTraversal(root2);

    cout << "Test Case 2: ";

    for(int x : ans2)
        cout << x << " ";

    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <memory>
#include <functional>

/*
    I am still in awe of why this works as at 15062026.
    I think I don't understand modern C++ for now.
    Inshallah we will change this one day.
*/

using namespace std;

struct TreeNode {
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, unique_ptr<TreeNode> l, unique_ptr<TreeNode> r)
        : val(x), left(std::move(l)), right(std::move(r)) {}
    // Destructor auto-generated: deletes left, which deletes its left, etc.
};

class Solution {
public:
    vector<int> inorderTraversal(const unique_ptr<TreeNode>& root) {
        vector<int> result;
        inorder(root, result);
        return result; // RVO/move, no copy
    }

private:
    void inorder(const unique_ptr<TreeNode>& node, vector<int>& result) {
        if (!node) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
};

// Helper to build trees easily in tests
unique_ptr<TreeNode> makeNode(int val,
                              unique_ptr<TreeNode> l = nullptr,
                              unique_ptr<TreeNode> r = nullptr) {
    return make_unique<TreeNode>(val, std::move(l), std::move(r));
}

void printVec(const vector<int>& v, const string& label) {
    cout << label << ": ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    /************************************************
        Test Case 1

                1
                 \
                  2
                 /
                3
    ************************************************/
    auto root1 = makeNode(1,
                    nullptr,
                    makeNode(2,
                        makeNode(3),
                        nullptr
                    )
                );

    auto ans1 = sol.inorderTraversal(root1);
    printVec(ans1, "Test Case 1");

    /************************************************
        Test Case 2

                    1
                  / \
                 2 3
                / \ \
               4 5 8
                  / \ /
                 6 7 9
    ************************************************/
    auto root2 = makeNode(1,
                    makeNode(2,
                        makeNode(4),
                        makeNode(5,
                            makeNode(6),
                            makeNode(7)
                        )
                    ),
                    makeNode(3,
                        nullptr,
                        makeNode(8,
                            makeNode(9),
                            nullptr
                        )
                    )
                );

    auto ans2 = sol.inorderTraversal(root2);
    printVec(ans2, "Test Case 2");

} // root1, root2 destructors run here. Entire trees auto-deleted. Zero leaks.
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{

public:
    Node *lchild;
    int data;
    Node *rchild;
    Node() {};      // declare empty Node class constructor.
    Node(int data); // declare Node class constructor that takes data
};

Node::Node(int data)
{
    // defining constructor that takes data as argument. Compare this format with the one in 94.BianryTreeInOrderTraversal.cpp where the constructor is in the class declaration.
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class Tree
{

private:
    Node *root;

public:
    Tree();
    ~Tree();
    void CreateTree();
    void PreOrder(Node *p);
    /*
        This variant passses class's private parameter in constructor.
        The API calls PreOrder() and then this function calls PreOrder(root) funtion on top.
        That way the API can't access the `root` node.
        But I think to make this water tighter then the function above `void PreOrder(Node *p)` should also have been private.

        This pattern is repeated for the other functions.
    */
    void PreOrder() { PreOrder(root); }

    void InOrder(Node *p);
    void InOrder() { InOrder(root); }

    void PostOrder(Node *p);
    void PostOrder() { PostOrder(root); }

    void LevelOrder(Node *p);
    void LevelOrder() { LevelOrder(root); }

    void iterativePreOrder(Node *P);
    void iterativePreOrder() { iterativePreOrder(root); }

    void iterativeInOrder(Node *p);
    void iterativeInOrder() { iterativeInOrder(root); }

    void iterativePostOrder(Node *p);
    void iterativePostOrder() { iterativePostOrder(root); }

    Node *generateTreeFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);

    int Height(Node *p);
    int Height() { return Height(root); }

    int Count(Node *p);
    int Count() {return Count(root); }

    int Sum(Node *p);
    int Sum() { return Sum(root); }

    int degree2NodeCount(Node *p);
    int degree2NodeCount() { return degree2NodeCount(root); }
};

// default constructor definition
Tree::Tree()
{
    root = nullptr;
}

// default destructor definition
Tree::~Tree()
{
    // ToDo
}

void Tree::CreateTree()
{
    Node *parent;
    Node *t;
    int x;

    queue<Node *> q; // A queue of Node pointer called q.

    root = new Node; // when you use new you must use delete unless this is being done on the stack then the destructor will be called automatically.
    cout << "Enter root data" << flush;
    cin >> x;

    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;

    // push parent root to the back of the queue
    q.emplace(root);

    while (!q.empty())
    {
        parent = q.front();
        q.pop(); // get the FIFO item from the queue.

        cout << "Enter left child of " << parent->data << ": " << flush;
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            /*
            The use of emplace is botched here? Lol. We are doing copy anyway so we are inefficient.
            Should be `q.emplace(nullptr, x, nullptr)`. Then we delete all these boiler plate above i.e.
            `t = new Node;` to avoid the expensive copy operation.
            */
            q.emplace(t);
            parent->lchild = t;
        }

        cout << "Enter right child of " << parent->data << "; " << flush;
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            q.emplace(t);
            parent->rchild = t;
        }
    }
}

void Tree::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree::InOrder(Node *p)
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << ", " << flush;
        InOrder(p->rchild);
    }
}

void Tree::PostOrder(Node *p)
{
    if (p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

// To traverse level order i.e. BFS you need a queue. To traverse DFS you need a stack.
void Tree::LevelOrder(Node *parent)
{
    queue<Node *> q;
    cout << parent->data << ", " << flush;
    // add the node to a queue.
    q.emplace(parent);

    while (!q.empty())
    {
        /*
            parent points to whatever is at the front of the queue.
            queue.front() does not remove the item, it simply gives you a reference to whatever item is at the front of the queue.
        */
        parent = q.front();
        // remove whatever is at the front of the queue
        q.pop();

        if (parent->lchild)
        {
            cout << parent->lchild->data << ", " << flush;
            q.emplace(parent->lchild); // then place the left child at the back of the queue
        }

        if (parent->rchild)
        {
            cout << parent->rchild->data << ", " << flush;
            q.emplace(parent->rchild);
        }
    }
}

// To do iterative DFS without recursion means we implement our own stack
void Tree::iterativePreOrder(Node *p)
{
    stack<Node *> stck;
    while (!(p == nullptr) || !stck.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << ", " << flush;
            stck.push(p);
            p = p->lchild;
        }
        else
        {
            p = stck.top(); // get most recently pushed item.
            stck.pop();     // delete it from the stack.
            p = p->rchild;
        }

        cout << endl;
    }
}

void Tree::iterativeInOrder(Node *p)
{
    stack<Node *> stck;

    while (!(p == nullptr) || !stck.empty())
    {
        if (p != nullptr)
        {
            stck.push(p);
            p = p->lchild;
        }
        else
        {
            p = stck.top();
            stck.pop();
            cout << p->data << ", " << flush;
        }
    }
    cout << endl;
}

void Tree::iterativePostOrder(Node *p)
{
    stack<long int> stck; // why long?
    long int temp;

    while (!(p == nullptr) || !stck.empty())
    {
        if (p != nullptr)
        {
            stck.push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stck.top();
            stck.pop();

            if (temp > 0)
            {
                stck.push(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }

    cout << endl;
}

// searchInOrder is just a local helper function to help us generate a tree from traversal in the function that follows next.
int searchInOrder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            return i;
        }
    }
    return -1;
}

Node *Tree::generateTreeFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return nullptr;
    }

    Node *node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return node;
    }

    int splitIndex = searchInOrder(inorder, inStart, inEnd, node->data);
    node->lchild = generateTreeFromTraversal(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = generateTreeFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

int Tree::Height(Node *p)
{
    int left = 0;
    int right = 0;

    if (p != nullptr)
    {
        left = Height(p->lchild);
        right = Height(p->rchild);

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }

    return 0;
}

int Tree::Count(Node *p)
{
    int x;
    int y;

    if (p != nullptr)
    {
        x = Count(p->lchild);
        y = Count(p->rchild);

        return x + y + 1; // plus 1 to include the current node that we are in
    }

    return 0;
}

int Tree::Sum(Node *p)
{
    int x, y;

    if (p != nullptr)
    {
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }

    return 0;
}

int Tree::degree2NodeCount(Node *p)
{
    int x, y;

    if (p != nullptr)
    {
        x = degree2NodeCount(p->lchild);
        y = degree2NodeCount(p->rchild);

        if (p->lchild && p->rchild)
        {
            return x + y + 1; // +1 counts the node that has both children?
        }
        else
        {
            return x + y; // ignores counting node if it does not have both children?
        }
    }

    return 0;
}

int main()
{
    Tree binarytree; // Create tree object on stack

    int preorder[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorder[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};

    int size = sizeof(inorder) / sizeof(inorder[0]);

    Node *p = binarytree.generateTreeFromTraversal(inorder, preorder, 0, size - 1);

    cout << "Preorder: " << flush;
    binarytree.PreOrder(p);
    cout << endl;

    cout << "Inorder: " << flush;
    binarytree.InOrder(p);
    cout << endl;

    cout << "Height: " << binarytree.Height(p) << endl;
    cout << "Count: : " << binarytree.Count(p) << endl;
    cout << "Sum: " << binarytree.Sum(p) << endl;
    cout << "# of degreee 2 nodes: " << binarytree.degree2NodeCount(p) << endl;

    return 0;
}
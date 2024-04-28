#include <bits/stdc++.h>
using namespace std;
// not solved
class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

void printSingles(Node *root, vector<int> &ans)
{
    // Base case
    if (root == NULL)
        return;

    // If this is an internal node, recur for left
    // and right subtrees
    if (root->left != NULL && root->right != NULL)
    {
        printSingles(root->left, ans);
        printSingles(root->right, ans);
    }

    // If left child is NULL and right is not,
    // print right child
    // and recur for right child
    else if (root->right != NULL)
    {
        ans.push_back(root->right->data);

        printSingles(root->right, ans);
    }

    // If right child is NULL and left is
    // not, print left child
    // and recur for left child
    else if (root->left != NULL)
    {
        ans.push_back(root->left->data);

        printSingles(root->left, ans);
    }
}

// void noSiblingHelp(Node *root, vector<int> &ans)
// {
//     if (root == nullptr)
//         return;

//     noSiblingHelp(root->left, ans);
//     if ((root->left == nullptr and root->right != nullptr) or (root->right == nullptr and root->left != nullptr))
//     {
//         int noSib = root->left == nullptr ? root->right->data : root->left->data;
//         ans.push_back(noSib);
//     }
//     noSiblingHelp(root->right, ans);
// }

vector<int> noSibling(Node *node)
{
    vector<int> ans;
    printSingles(node, ans);
    return ans;
}

int main()
{
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

//nhi ho rha
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

bool isIsomorphic2(Node *n1, Node *n2)
{
    // Both roots are NULL, trees isomorphic by definition
    if (n1 == NULL && n2 == NULL)
        return true;

    // Exactly one of the n1 and n2 is NULL, trees not isomorphic
    if (n1 == NULL || n2 == NULL)
        return false;

    if (n1->data != n2->data)
        return false;

    // There are two possible cases for n1 and n2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"
    return (isIsomorphic2(n1->left, n2->left) && isIsomorphic2(n1->right, n2->right)) ||
           (isIsomorphic2(n1->left, n2->right) && isIsomorphic2(n1->right, n2->left));
}
// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1, Node *root2)
{
    // add code here.
    return isIsomorphic2(root1, root2);
}

int main()
{
    return 0;
}
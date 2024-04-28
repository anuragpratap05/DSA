#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val)
    {
        this->data = val;
    }
};

Node *rightMostNode(Node *root, Node *curr)
{
    while (root->right != nullptr and root->right != curr)
        root = root->right;

    return root;
}

Node *morrisInorder(Node *root)
{
    Node *curr = root;

    Node *dummy = new Node(-1);
    Node *prev = dummy;

    while (curr != nullptr)
    {
        Node *l = curr->left;
        if (l == nullptr)
        {
            // cout << curr->data << " ";
            curr->left = prev;
            prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            Node *rmNode = rightMostNode(l, curr);
            if (rmNode->right == nullptr) // thread creation time
            {
                rmNode->right = curr;
                curr = curr->left;
            }
            else // thread destrot time
            {
                rmNode->right = nullptr;
                // cout << curr->data << " ";
                curr->left = prev;
                prev->right = curr;
                prev = curr;
                curr = curr->right;
            }
        }
    }
    Node *hd = dummy->right;
    dummy->right = nullptr;
    hd->left = nullptr;
    return hd;
}

Node *midOfList(Node *head)
{
    Node *curr = head;
    if (curr == nullptr or curr->right == nullptr)
        return curr;
    Node *s = curr;
    Node *f = curr;
    while (f->right != nullptr and f->right->right != nullptr)
    {
        s = s->right;
        f = f->right->right;
    }
    return s;
}

void createLinks(Node *&curr, Node *&p)
{
    p->right = curr;
    curr->left = p;
    p = curr;
    curr = curr->right;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == nullptr or list2 == nullptr)
        return list1 == nullptr ? list2 : list1;

    Node *dummy = new Node(-1), *p = dummy;
    Node *c1 = list1, *c2 = list2;

    while (c1 and c2)
    {
        if (c1->data < c2->data)
            createLinks(c1, p);
        else
            createLinks(c2, p);
    }
    if (c1)
    {
        p->right = c1;
        c1->left = p;
    }
    else
    {
        p->right = c2;
        c2->left = p;
    }
    Node *hd = dummy->right;
    dummy->right = nullptr;
    hd->left = nullptr;
    return hd;
}

Node *sortDoubly(Node *head)
{
    if (head == nullptr or head->right == nullptr)
        return head;

    Node *midNode = midOfList(head);
    Node *f = midNode->right;
    midNode->right = nullptr;
    f->left = nullptr;

    Node *leftSortedList = sortDoubly(head);
    Node *rightSortedList = sortDoubly(f);
    return mergeTwoLists(leftSortedList, rightSortedList);
}

Node *treeToDoublyList(Node *root)
{
    if (root == nullptr)
        return nullptr;
    return morrisInorder(root);
}

Node *convertDoublyLLtoBst(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *root = midOfList(head);
    Node *prev = root->left;
    Node *forw = root->right;
    root->left = root->right = nullptr;
    if (prev != nullptr)
        prev->right = nullptr;
    else
        head = nullptr;
    if (forw != nullptr)
        forw->left = nullptr;
    root->left = convertDoublyLLtoBst(head);
    root->right = convertDoublyLLtoBst(forw);

    return root;
}

// space O(1)******
Node *binaryTreeToBST(Node *root)
{
    if (root == nullptr)
        return root;

    // ALGO: BT ---> LL  ----> Sorted LL  ---->BST
    Node *curr = root;
    curr = treeToDoublyList(curr);
    curr = sortDoubly(curr);
    curr = convertDoublyLLtoBst(curr);
    return curr;
}


int main()
{
    return 0;
}
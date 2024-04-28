#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        data = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        data = _val;
        left = _left;
        right = _right;
    }
};

void prettyPrintTree(Node *node, string prefix = "", bool isLeft = true)
{
    if (node == nullptr)
    {
        cout << "Empty tree";
        return;
    }

    if (node->right)
    {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left)
    {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

Node *getRightMostNode(Node *node, Node *curr)
{
    if (node == nullptr)
        return nullptr;
    while (node->right != nullptr and node->right != curr)
        node = node->right;
    return node;
}

Node *morrisInorder(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *dummy = new Node(-1), *p = dummy;
    vector<int> ans;
    Node *curr = root;
    while (curr != nullptr)
    {
        Node *l = curr->left;
        if (l == nullptr)
        {
            p->right = curr;
            curr->left = p;
            p = curr;
            curr = curr->right;
        }
        else
        {
            Node *rmnd = getRightMostNode(l, curr);
            if (rmnd->right == nullptr)
            {
                rmnd->right = curr;
                curr = curr->left;
            }
            else
            {
                rmnd->right = nullptr;
                p->right = curr;
                curr->left = p;
                p = curr;
                curr = curr->right;
            }
        }
    }
    Node *hd = dummy->right;
    dummy->right = nullptr;
    hd->left = nullptr;
    return hd;
}

Node *mergeTwoSorteddoublyLL(Node *h1, Node *h2)
{
    if (h1 == nullptr or h2 == nullptr)
        return h1 == nullptr ? h2 : h1;

    Node *dummy = new Node(-1), *c1 = h1, *c2 = h2, *p = dummy;

    while (c1 and c2)
    {
        if (c1->data < c2->data)
        {
            p->right = c1;
            c1->left = p;
            p = c1;
            c1 = c1->right;
        }
        else
        {
            p->right = c2;
            c2->left = p;
            p = c2;
            c2 = c2->right;
        }
    }
    if (c1 != nullptr)
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

Node *getMid(Node *head)
{
    if (head == nullptr or head->right == nullptr)
        return head;
    Node *s = head, *f = head;
    while (f->right and f->right->right)
    {
        s = s->right;
        f = f->right->right;
    }
    return s;
}

Node *sortDoubly(Node *head)
{
    if (head == nullptr or head->right == nullptr)
        return head;
    Node *midNode = getMid(head);
    Node *rh = midNode->right;
    midNode->right = nullptr;
    rh->left = nullptr;
    Node *leftSorted = sortDoubly(head);
    Node *rightSorted = sortDoubly(rh);

    return mergeTwoSorteddoublyLL(leftSorted, rightSorted);
}

Node *sortedDoublyLLToBst(Node *head)
{
    if (head == nullptr or head->right == nullptr)
        return head;
    Node *root = getMid(head);
    Node *p = root->left;
    Node *rh = root->right;
    Node *lh = p == nullptr ? nullptr : head;
    if (p)
        p->right = nullptr;
    rh->left = root->left = root->right = nullptr;
    root->left = sortedDoublyLLToBst(lh);
    root->right = sortedDoublyLLToBst(rh);
    return root;
}

Node *treeToDoublyList(Node *root)
{
    return morrisInorder(root);
}

Node *binaryTreeToBST(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *curRoot = root;
    curRoot = treeToDoublyList(root);
    curRoot = sortDoubly(curRoot);
    return sortedDoublyLLToBst(curRoot);
}

int main()
{
    vector<int> nums = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    Node *head = new Node(nums[0]);
    Node *prev = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *node = new Node(nums[i]);
        prev->right = node;
        node->left = prev;
        prev = prev->right;
    }
    Node *root = sortedDoublyLLToBst(head);
    prettyPrintTree(root);
    return 0;
}
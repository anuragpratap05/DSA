#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *rightMostNode(TreeNode *root, TreeNode *curr)
{
    if (root == nullptr)
        return root;
    while (root->right != nullptr and root->right != curr)
        root = root->right;

    return root;
}

bool morrisInorder(TreeNode *root)
{
    TreeNode *curr = root;
    int prevVal = INT_MIN;
    bool isBst = true;
    bool firstrun = true;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            if (!firstrun and prevVal >= curr->val)
            {
                isBst = false;
            }
            firstrun = false;
            prevVal = curr->val;
            curr = curr->right;
        }
        else
        {
            TreeNode *rmNode = rightMostNode(l, curr);
            if (rmNode->right == nullptr) // thread creation time
            {
                rmNode->right = curr;
                curr = curr->left;
            }
            else // thread destrot time
            {
                rmNode->right = nullptr;
                if (!firstrun and prevVal >= curr->val)
                {
                    isBst = false;
                }
                firstrun = false;
                prevVal = curr->val;
                curr = curr->right;
            }
        }
    }
    return isBst;
}

bool isValidBSTMorrisInOrder(TreeNode *root)
{
    return morrisInorder(root);
}

// class trplet
// {
// public:
//     TreeNode *smallestNd = nullptr, *largestNd = nullptr;
//     bool isBst = true;
//     trplet(){};
//     trplet(TreeNode *smallestNd, bool isBst, TreeNode *largestNd)
//     {
//         this->smallestNd = smallestNd;
//         this->isBst = isBst;
//         this->largestNd = largestNd;
//     }
// };

// TreeNode *getMinimumNode(TreeNode *leftMinNd, TreeNode *root, TreeNode *rightMinNd)
// {
//     TreeNode *minNode;
//     if (!leftMinNd and !rightMinNd)
//     {
//         minNode = root;
//     }
//     else if (!leftMinNd)
//     {
//         minNode = root->val < rightMinNd->val ? root : rightMinNd;
//     }
//     else if (!rightMinNd)
//     {
//         minNode = root->val < leftMinNd->val ? root : leftMinNd;
//     }
//     else
//     {
//         TreeNode *posiblMin = root->val < rightMinNd->val ? root : rightMinNd;
//         minNode = posiblMin->val < leftMinNd->val ? posiblMin : leftMinNd;
//     }
//     return minNode;
// }

// TreeNode *getMaximumNode(TreeNode *leftMaxNd, TreeNode *root, TreeNode *rightMaxNd)
// {
//     TreeNode *maxNode;
//     if (!leftMaxNd and !rightMaxNd)
//     {
//         maxNode = root;
//     }
//     else if (!leftMaxNd)
//     {
//         maxNode = root->val > rightMaxNd->val ? root : rightMaxNd;
//     }
//     else if (!rightMaxNd)
//     {
//         maxNode = root->val > leftMaxNd->val ? root : leftMaxNd;
//     }
//     else
//     {
//         TreeNode *posiblMax = root->val > rightMaxNd->val ? root : rightMaxNd;
//         maxNode = posiblMax->val > leftMaxNd->val ? posiblMax : leftMaxNd;
//     }
//     return maxNode;
// }

// trplet isValidBSTRecursion(TreeNode *root)
// {
//     if (root->left == nullptr and root->right == nullptr)
//         return trplet(root, true, root);

//     trplet leftAns = root->left ? isValidBSTRecursion(root->left) : trplet();
//     trplet rightAns = root->right ? isValidBSTRecursion(root->right) : trplet();

//     trplet curTrplet;
//     if (leftAns.isBst and rightAns.isBst)
//     {
//         bool isCurNodeBst = true;
//         if (leftAns.largestNd and leftAns.largestNd->val >= root->val)
//         {
//             isCurNodeBst = false;
//         }
//         if (rightAns.smallestNd and rightAns.smallestNd->val <= root->val)
//         {
//             isCurNodeBst = false;
//         }
//         if (isCurNodeBst)
//         {
//             curTrplet.isBst = true;
//             curTrplet.smallestNd = getMinimumNode(leftAns.smallestNd, root, rightAns.smallestNd);
//             curTrplet.largestNd = getMaximumNode(leftAns.largestNd, root, rightAns.largestNd);
//         } // calculate min and max
//         else
//         {
//             curTrplet.isBst = false;
//         }
//     }
//     else
//     {
//         curTrplet.isBst = false;
//     }
//     return curTrplet;
// }

class trplet
{
public:
    long smallest = 1e13, largest = -(1e13);
    bool isBst = true;
};

trplet isValidBSTRecursionSimple(TreeNode *root)
{
    if (root == nullptr)
    {
        trplet base;
        return base;
    }

    trplet leftAns = isValidBSTRecursionSimple(root->left);
    if (!leftAns.isBst)
        return leftAns;
    trplet rightAns = isValidBSTRecursionSimple(root->right);

    trplet curAns;
    if (leftAns.isBst and rightAns.isBst and root->val > leftAns.largest and root->val < rightAns.smallest)
    {
        curAns.isBst = true;
        curAns.smallest = root->val < leftAns.smallest ? root->val : leftAns.smallest;
        curAns.largest = root->val > rightAns.largest ? root->val : rightAns.largest;
    }
    else
        curAns.isBst = false;

    return curAns;
}

bool isValidBST(TreeNode *root)
{
    // return isValidBSTRecursion(root).isBst; //method1
    // return isValidBSTMorrisInOrder(root);   //method2
    // return isValidBSTRecursionSimple(root).isBst;  //method3
}

int main()
{
    return 0;
}
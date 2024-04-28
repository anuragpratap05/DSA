#include<bits/stdc++.h>
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


//method1 morris traversal
//isme agr ek variable previous lelo to vector wala space nhi lgega
TreeNode *rightmost_node(TreeNode *root, TreeNode *curr)
{
    while (root->right != nullptr and root->right != curr)
    {
        root = root->right;
    }
    return root;
}

vector<int> morris_inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<int> ans;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        TreeNode *left = curr->left;
        if (left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *rmnode = rightmost_node(left, curr);
            if (rmnode->right == nullptr)
            {
                rmnode->right = curr;
                curr = curr->left;
            }
            else
            {
                rmnode->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}

bool isValidBST(TreeNode *root)
{

    vector<int> ans = morris_inorder(root);
    if (ans.size() <= 1)
    {
        return true;
    }

    for(int i=1;i<ans.size();i++)
    {
        if(ans[i]<=ans[i-1])
        {
            return false;
        }
    }
    return true;
}




// method2 return type
class trp
{
public:
    long mini = 1e13;
    bool is_bst = true;
    long maxi = -(1e13);
};

trp isValidBST_help(TreeNode *root)
{
    if (root == nullptr)
    {
        trp base;
        return base;
    }

    trp left = isValidBST_help(root->left);
    if (!left.is_bst)
    {
        return left;
    }
    trp right = isValidBST_help(root->right);
    if (!right.is_bst)
    {
        return right;
    }

    trp mytrp;
    if ((left.is_bst == true) and (right.is_bst == true) and (root->val > left.maxi) and (root->val < right.mini))
    {
        mytrp.is_bst = true;


        //ye bhi shi

        // if(left.mini<root->val)
        // {
        //     mytrp.mini = left.mini;
        // }
        // else
        // {
        //     mytrp.mini = root->val;
        // }

        // if (right.maxi > root->val)
        // {
        //     mytrp.maxi = right.maxi;
        // }
        // else
        // {
        //     mytrp.maxi = root->val;
        // }



        // ye bhi shi

        // if (left.mini < right.mini)
        // {
        //     if (left.mini < root->val)
        //     {
        //         mytrp.mini = left.mini;
        //     }
        //     else
        //     {
        //         mytrp.mini = root->val;
        //     }
        // }
        // else
        // {
        //     if (right.mini < root->val)
        //     {
        //         mytrp.mini = right.mini;
        //     }
        //     else
        //     {
        //         mytrp.mini = root->val;
        //     }
        // }

        // if (left.maxi > right.maxi)
        // {
        //     if (left.maxi > root->val)
        //     {
        //         mytrp.maxi = left.maxi;
        //     }
        //     else
        //     {
        //         mytrp.maxi = root->val;
        //     }
        // }
        // else
        // {
        //     if (right.maxi > root->val)
        //     {
        //         mytrp.maxi = right.maxi;
        //     }
        //     else
        //     {
        //         mytrp.maxi = root->val;
        //     }
        // }
    }
    else
    {
        mytrp.is_bst = false;
    }
    return mytrp;
}

bool isValidBST_(TreeNode *root)
{

    return isValidBST_help(root).is_bst;
}

void fillit(TreeNode* root,stack<TreeNode*>& st)
{
    while(root!=nullptr)
    {
        st.push(root);
        root=root->left;
    }
}




//Method3  using space of self made stack

bool isValidBST_3(TreeNode *root)
{
    stack<TreeNode*>st;
    while(root!=nullptr)
    {
        st.push(root);
        root=root->left;

    }
    long p=1e14;
    long c;

    while(!st.empty())
    {
        TreeNode* rmnode=st.top();
        st.pop();
        
        c=rmnode->val;
        if (p != 1e14)
        {
            if(p>c)
            {
                return false;
            }
        }
        p=c;
        fillit(rmnode->right,st);
    }
    return true;
}

int main()
{
    return 0;
}
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
   vector<vector<int>>ans;
   //vector<vector<int>> ans;
   if (root == nullptr)
   {
       return ans;
   }
   queue<TreeNode* >q;
   stack<TreeNode*>s;
   q.push(root);
   int level=0;
   while(!q.empty())
   {
       int size=q.size();
       while(size--)
       {
           TreeNode* node=q.front();
           q.pop();
           if(ans.size()==level)
           {
               ans.push_back({});
           }
           ans[level].push_back(node->val);
           //cout<<node->val;//ec
           if(level%2==0)
           {
               if(node->left!=nullptr)
               {
                   s.push(node->left);
               }
               if (node->right != nullptr)
               {
                   s.push(node->right);
               }
           }
           else{
               if (node->right != nullptr)
               {
                   s.push(node->right);
               }
               if (node->left != nullptr)
               {
                   s.push(node->left);
               }
           }
       }
       level++;
       while(!s.empty())
       {
           q.push(s.top());
           s.pop();
       }
   }
   return ans;

}

int main()
{
    return 0;
}
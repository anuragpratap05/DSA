#include<bits/stdc++.h>
using namespace std;

// leetcode validate bst
TreeNode* rightmost(TreeNode* node,TreeNode* curr)
{
    while(  (node->right != NULL and node->right !=curr)  )
    {
        node=node->right;
    }
    return node;
}

void morristraversal(TreeNode* root,vector<int>& ans)
{
    TreeNode* curr=root;

    while(curr!=NULL)
    {
      TreeNode* left=curr->left;
      //TreeNode* righmost_node=rightmost(left,curr);
      if(left==NULL)
      {
          ans.push_back(curr->val);
          curr=curr->right;
      }
      else
      {
          
      
          TreeNode* righmost_node=rightmost(left,curr);
          if(righmost_node->right == NULL)
          {
              righmost_node->right=curr;
              curr=curr->left;
          }
          else
          {
              righmost_node->right=NULL;
              ans.push_back(curr->val);
              curr=curr->right;
          } 
      }
    }
}

vector<int> morrisInTraversal(TreeNode* root) {
    
    vector<int> ans;
    morristraversal(root,ans);
    return ans;
    
}

int main()
{

}


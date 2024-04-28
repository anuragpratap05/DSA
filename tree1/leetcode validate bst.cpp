/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pushall(TreeNode* node,stack<TreeNode*>& st)
{
    while(node!= NULL)
    {
        st.push(node);
        node=node->left;
    }
}
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
       pushall(root,st);
        vector<int> ans;
        long prev= -(long)1e13 ;
       while(!st.empty())
       {
           TreeNode* node=st.top();
           if(prev>=node->val)
           {    
               return false;
            }
           prev=node->val;
           //ans.push_back(node->val);
           st.pop();
           if(node->right!=NULL)
           {
               pushall(node->right,st);
           }
       }
   
    return true;
    }
   
};
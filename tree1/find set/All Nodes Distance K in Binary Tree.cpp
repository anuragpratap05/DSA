/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// leetcode 863



class Solution {
public:
    
    void k_down(TreeNode* root,int k,vector<int>& ans,TreeNode* blok)
 {
     if(k<0)
     {
         return;
     }
     if(blok==root)
     {
         return;
     }
     if(root==nullptr)
     {
         return;
     }

     if(k==0)
     {
         ans.push_back(root->val);
     }

     k_down(root->left,k-1,ans,blok);
     k_down(root->right,k-1,ans,blok);
     return;
 }

 int find(int ele,TreeNode* root,int k,vector<int>& ans)
{
    if(root==nullptr)
    {
        return 0;
    }
    if(root->val==ele)
    {
        k_down(root,k,ans,NULL);
        return 1;
    }

    int ld,rd;
    ld=0,rd=0;
    
    ld=find(ele,root->left,k,ans);
    if(ld!=0)
    {
        k_down(root,k-ld,ans,root->left);
        return ld+1;
    }



    rd=find(ele,root->right,k,ans);
    if(rd!=0)
    {
        k_down(root,k-rd,ans,root->right);
        return rd+1;
    }
     return 0;

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
         vector<int> ans;

    int c=find(target->val,root,k,ans);
    //vector<int> ans;

    
        
    

    return ans;
        
    }
};
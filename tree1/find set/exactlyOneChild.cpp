

void help(TreeNode* root,vector<int>& ans)
{
  if(root==nullptr or(root->left==nullptr and root->right==nullptr))
  {
    return;
  }

  if(root->left==nullptr or root->right==nullptr)
  {
    ans.push_back(root->val);
  }

  help(root->left,ans);
  help(root->right,ans);
  return;
}

vector<int> exactlyOneChild(TreeNode* root)
{
  vector<int> ans;

  help(root,ans);
  return ans;
}
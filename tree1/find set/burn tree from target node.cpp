void print(Node* root,int time,Node* block,vector<vector<int>>& ans)
{
    if(root == nullptr or root== block)
    {
        return;
    }
    if(ans.size()==time)
    {
        ans.push_back({});
        
    }
    ans[time].push_back(root->val);
    print(root->left,time+1,block);
    print(root->right,time+1,block);
    return;
}


int burningtree(Node* root, int target,vector<vector<int>>& ans)
{
     if(root==null)
    {
        return -1;
    }
    if(root->val==target)
    {
        print(root,0,NULL,ans);
        return 1;
    }

    int ld=-1;
    int rd=-1;
    ld=minTime(root->left,target);
    if(ld!=-1)
    {
        print(root,ld,root->left,ans);
        return ld+1;
    }
    if(rd!=-1)
    {
        print(root,rd,root->left,ans);
        return rd+1;
    }
    return -1;
}

int minTime(Node* root, int target) 
{
   
    vector<vector<int>> ans;
    int c=burningtree(root,target,ans);
    return c;






}
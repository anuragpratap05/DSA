void print(Node* root,int time,Node* block,vector<vector<int>>& ans,map<int,int >& m)
{
    if(root == nullptr or root== block or m[root->val])
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


int burningtree(Node* root, int target,vector<vector<int>>& ans,map<int,int >& m)
{
     if(root==null)
    {
        return -1;
    }
    if(root->val==target)
    {
        if(!m[root->val])
        {
            print(root,0,NULL,ans);
        
            return 1;
        }
        return -2;
    }

    
    int ld=minTime(root->left,target);
    if(ld>0)
    {
        if(!m[root->val])
        {
            print(root,ld,root->left,ans);
            return ld+1;
        }
        return -2;
    }

    if(ld==-2)
    {
        return -2;
    }

    if(rd>0)
    {
        if(!m[root->val])
        {
            print(root,rd,root->left,ans);
            return rd+1;
        }
        return -2;
    }

    if(rd==-2)
    {
        return -2;
    }
    return -1;
}

int minTime(Node* root, int target) 
{
   
    vector<vector<int>> ans;
    vector<int> waterset;
    map<int,int >m;
    for(auto ele:waterset)
    {
        m[ele]=1;
    }
    int c=burningtree(root,target,ans,m);
    return c;






}
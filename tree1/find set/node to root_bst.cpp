#include<bits/stdc++.h>
using namespace std;

bool node_to_root(Node* root,int target,vector<int>& ans)
{
    NODE* curr= root;
    while(curr!=NULL)
    {
        ans.push_back(curr->val);
        if(curr->val == target)
        {
            return true;
        }
        else if(curr->val < target)
        {
            curu =curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    return false;
}
int main()
{

}
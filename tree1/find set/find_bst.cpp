#include<bits/stdc++.h>
using namespace std;

bool find(NODE* root,int target)
{
    NODE* curr= root;
    while(curr!=NULL)
    {
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
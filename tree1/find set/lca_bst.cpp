#include<bits/stdc++.h>
using namespace std;

Node* lca(Node* root, Node* p,Node* q)
{
    Node* curr=root;
    while(curr!=NULL)
    {
        if(p->val < curr->val  and q->val< curr->val)
        {
            curr=curr->left;
        }
        else if(p->val > curr->val  and q->val > curr->val)
        {
            curr=curr->right;
        }
        else{
            return curr;
        }

    }
}

int main()
{

}
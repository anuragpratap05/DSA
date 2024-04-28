#include<bits/stdc++.h>
using namespace std;

//code is wrong not passing on leetcode


//**

// ab pass ho rha h



class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;

    }
};



vector<ListNode*>  segregate(ListNode* head, int pivotIdx)
{
    if(head==nullptr or head->next==nullptr)
    {
        return {head,head,head};
    }
        ListNode* pivotNode = head;
        while (pivotIdx-- > 0)
            pivotNode = pivotNode->next;

        ListNode* large = new ListNode(-1), *small = new ListNode(-1), *sp = small, *lp = large, *curr = head;
        while (curr != nullptr) {
            if (curr != pivotNode && curr->val <= pivotNode->val) {
                sp->next = curr;
                sp = sp->next;
            } else if (curr != pivotNode) {
                lp->next = curr;
                lp = lp->next;
            }
            curr = curr->next;
        }

        sp->next = lp->next = pivotNode->next = nullptr;
        // sp.next = pivotNode;
        // pivotNode.next = large.next;
        // return small.next;

        ListNode* leftHead = small->next == pivotNode ? nullptr : small->next;
        ListNode* rightHead = large->next;
        return  { leftHead, pivotNode, rightHead };
    

}

 int getlen(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }

vector<ListNode*> mergelist(vector<ListNode*> left,ListNode* pivotNode,vector<ListNode*> right)
{
        vector<ListNode*> myRes(2,NULL) ;

      if (left[0] != nullptr && right[0] != nullptr) {
            myRes[0] = left[0];
            myRes[1] = right[1];

            left[1]->next = pivotNode;
            pivotNode->next = right[0];
        } else if (right[0] != nullptr) {
            myRes[0] = pivotNode;
            myRes[1] = right[1];

            pivotNode->next = right[0];
        } else {
            myRes[0] = left[0];
            myRes[1] = pivotNode;

            left[1]->next = pivotNode;
        }

        return myRes;
}

   

vector<ListNode*> quickSort_(ListNode *head)
{
    if(head==nullptr or head->next== nullptr )
    {
        return {head,head};
    }

    int len=getlen(head);
    int pivotidx=len/2;
    vector<ListNode*> vec   = segregate(head,pivotidx);
    ListNode* h1=vec[0];
    
    ListNode* pivotnode=vec[1];
    ListNode* h2=vec[2];
    

    vector<ListNode*> left= quickSort_(h1);
    vector<ListNode*> right= quickSort_(h2);

    return mergelist(left,pivotnode,right);

}

ListNode *quickSort(ListNode *head)
{
    return quickSort_(head)[0];
}

int main()
{
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// DOUBT
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class compa{
    public:
        // bool operator()(const ListNode*  &a,const ListNode*  &b)const{
            //& lga rhe hai to compilation err aa rha hai 
        bool operator()(const ListNode *a, const ListNode *b) const
        {
            return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue < ListNode *, vector<ListNode *>, compa > pq;
    for(auto &x:lists)
    {
        pq.push(x);
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;
    while (!pq.empty())
    {
        ListNode *rn = pq.top();
        pq.pop();
        p->next = rn;
        p = p->next;
        if(rn->next!=nullptr)
        {
            pq.push(rn->next);
        }
    }
    p->next = nullptr;
    return dummy->next;
}

int main()
{
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class comp{
    public:
        bool operator()(const ListNode *a, const ListNode *b) const
        {
            return a->val>b->val;
        }
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{

    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] != nullptr)
            pq.push(lists[i]);
    }
    while (!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();

        p->next = node;
        p = p->next;
        if (node->next != nullptr)
            pq.push(node->next);
    }
    p->next = nullptr;
    return dummy->next;
}

int main()
{
    return 0;
}
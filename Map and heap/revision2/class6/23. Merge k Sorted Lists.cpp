#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// kl log(kl)  , where l= avg length of linkedlist
ListNode *mergeKLists2(vector<ListNode *> &lists)
{
    vector<int> nums;
    for (ListNode *head : lists)
    {
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    sort(nums.begin(), nums.end());

    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    for (int ele : nums)
    {
        ListNode *curNode = new ListNode(ele);
        prev->next = curNode;
        prev = curNode;
    }
    return dummy->next;
}

class comp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return b->val < a->val;
    }
};

// O(kl log k)
ListNode *mergeKLists3(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    for (ListNode *head : lists)
    {
        if (head != nullptr)
            pq.push(head);
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    while (!pq.empty())
    {
        ListNode *minNode = pq.top();
        pq.pop();
        // if(minNode==nullptr)
        //     continue;

        ListNode *curNode = new ListNode(minNode->val);
        prev->next = curNode;
        prev = curNode;
        if (minNode->next != nullptr)
            pq.push(minNode->next);
    }
    return dummy->next;
}

ListNode *mergeTwoSortedLinkedLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr or list2 == nullptr)
    {
        return list1 == nullptr ? list2 : list1;
    }
    ListNode *c1 = list1;
    ListNode *c2 = list2;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    while (c1 != nullptr and c2 != nullptr)
    {
        if (c1->val < c2->val)
        {
            ListNode *curNode = new ListNode(c1->val);
            prev->next = curNode;
            prev = curNode;
            c1 = c1->next;
        }
        else
        {
            ListNode *curNode = new ListNode(c2->val);
            prev->next = curNode;
            prev = curNode;
            c2 = c2->next;
        }
    }
    if (c1 == nullptr)
    {
        prev->next = c2;
    }
    else
    {
        prev->next = c1;
    }
    return dummy->next;
}

ListNode *mergeHelper(vector<ListNode *> &lists, int s, int e)
{
    if (s >= e)
    {
        return nullptr;
    }

    int mid = (s + e) / 2;

    ListNode *leftSorted = mergeHelper(lists, s, mid);
    ListNode *rightSorted = mergeHelper(lists, mid + 1, e);

    return mergeTwoSortedLinkedLists(leftSorted, rightSorted);
}

// O(l logk) -> devide and conquer
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return mergeHelper(lists, 0, lists.size() - 1);
}

int main()
{
    return 0;
}
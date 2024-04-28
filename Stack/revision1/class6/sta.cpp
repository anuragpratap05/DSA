#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next = nullptr;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class my_ll
{
    public:
    ListNode *head=nullptr;
    void addfirst(int data)
    {
        ListNode *new_node = new ListNode(data);
        if (head == nullptr)
        {
            head = new_node;
        }
        else{
            ListNode *f = head;
            new_node->next = f;
            head = new_node;
        }
    }

    int get_first()
    {
        return head->val;
    }

    void remove_first()
    {
        head = head->next;
    }

    int size()
    {
        if(head==nullptr)
        {
            return 0;
        }
        else
            return 1;
    }
};

class my_stack
{
public:
    my_ll l;

    void push(int data)
    {
        l.addfirst(data);
    }
    void pop()
    {
        if (l.size() == 0)
        {
            cout << " stack is empty";
        }
        else
            l.remove_first();
    }
    int top()
    {
        return l.get_first();
    }

    bool empty()
    {
        if (l.size() == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    my_stack st;
    st.push(1);
    st.push(2);

    st.push(7);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}
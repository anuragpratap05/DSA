#include<bits/stdc++.h>
using namespace std;




  class ListNode{
    public:
      int val=0;;
      ListNode* next=nullptr;
      
    
      

  };

 


ListNode* middleNode(ListNode* head)
{
    ListNode* slow=head,*fast=head;
    while(fast!=nullptr and fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;


}

int main()
{
    return 0;
}
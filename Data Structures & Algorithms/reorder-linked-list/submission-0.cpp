/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    
public:
    void reorderList(ListNode* head) {
        if(head==NULL)return;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            if(fast->next!=NULL)
            {
                fast=fast->next->next;
            }
            else fast =NULL;
        }
        ListNode * curr = slow->next;
        ListNode*prev=NULL;
        slow->next=NULL;

        while(curr!=NULL)
        {
            ListNode *temp_next =curr->next;
            curr->next=prev;
            prev=curr;
            curr = temp_next;
        }
        ListNode* curr1 = head,*curr2 = prev;
        while(curr1!=NULL && curr2!=NULL)
        {
            ListNode *temp_next = curr1->next;
            curr1->next=curr2;
            curr1 = temp_next;
            ListNode*temp_next2 = curr2->next;
            curr2->next = curr1;
            curr2 = temp_next2; 
        }
       
    
    }
};

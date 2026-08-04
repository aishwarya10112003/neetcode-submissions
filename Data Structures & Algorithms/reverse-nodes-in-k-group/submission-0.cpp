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
    ListNode* helper(ListNode*node,int k)
    {
        ListNode* curr=node;
        for(int i=0;i<k;i++)
        {
            if(curr==nullptr)return nullptr;
            else curr=curr->next;
        }
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode * dummy = new ListNode(0);
       dummy->next=head;
       ListNode *groupPrev=dummy;
       while(true)
       {
            ListNode *kth = helper(groupPrev,k);
            if(kth==nullptr)break;

            ListNode *groupHead = groupPrev->next;
            ListNode *curr = groupPrev->next;
            ListNode *prev = kth->next;
            ListNode *groupNext=kth->next;
            while(curr!=groupNext)
            {
                ListNode *temp_next = curr->next;
                curr->next=prev;
                prev = curr;
                curr=temp_next;
            }
            groupPrev->next = kth;
            groupPrev = groupHead;
            
       }
       return dummy->next;

    }







};

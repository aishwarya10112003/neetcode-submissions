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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode*curr1=l1,*curr2=l2,*curr=dummy;
        int carry =0;
        while(curr1!=NULL || curr2!=NULL||carry>0)
        {
            int num1=0,num2=0;
            ListNode *new_node = new ListNode(0);
            if(curr1!=NULL)num1=curr1->val;
            if(curr2!=NULL)num2=curr2->val;
            int value = num1+num2+carry;
            carry=0;
            if(value>=10)
            {
                carry = 1;
                value = value%10;
            }
            new_node->val = value;
            curr->next = new_node;
            curr = curr->next;
            if(curr1!=NULL)curr1=curr1->next;
            if(curr2!=NULL)curr2=curr2->next;

        }
        return dummy->next;
    }
};

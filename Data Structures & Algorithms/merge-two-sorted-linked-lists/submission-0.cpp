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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dummy = new ListNode(0);
        ListNode * tail=dummy;
        while(list1!=NULL&&list2!=NULL)
        {
            int val1=list1->val;
            int val2=list2->val;
            if(val1<=val2)
            {
                tail->next=list1;
                tail = tail->next;
                list1=list1->next;
            }
            else 
            {
                tail->next=list2;
                tail = tail->next;
                list2=list2->next;
            }
        }
        while(list1!=NULL)
        {
            tail->next=list1;
            list1=list1->next;
            tail=tail->next;
        }
        while(list2!=NULL)
        {
            tail->next=list2;
            list2=list2->next;
            tail=tail->next;
        }
        return dummy->next;
    }
};

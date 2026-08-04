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
    struct compare{
        bool operator()(ListNode* A,ListNode *B)
        {
            return A->val>B->val;
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        ListNode* dummy = new ListNode(0);
        ListNode*curr=dummy;
        for(ListNode*temp:lists)
        {
            if(temp!=nullptr)
            pq.push(temp);
        }
        while(!pq.empty())
        {
            ListNode *smallest=pq.top();pq.pop();
            curr->next=smallest;
            curr=curr->next;
            if(smallest->next!=nullptr)
            {
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }










};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // find size of head
        int sz = 0;
        ListNode* curr = head;

        while (curr)
        {
            ++sz;
            curr = curr->next;
        }

        // move to head[nth]
        int indx = 0;
        curr = head;

        ListNode* currP = nullptr;
        while (indx < sz-n)
        {
            if (indx == sz-n-1)
                currP = curr;
            curr = curr->next;
            ++indx;
        }

        // curr->prev->next = curr->next;

        if (currP == nullptr)
            return head->next;
        
        currP->next = curr->next;

        return head;
    }
};

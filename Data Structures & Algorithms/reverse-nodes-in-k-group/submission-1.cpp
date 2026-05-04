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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head)
            return head;
        
        ListNode* l = head;
        ListNode* r = l;

        bool setHead = false;
        ListNode* prevL = new ListNode(0, head);
        while (true)
        {
            int currSize = 0;
            while (currSize < k && r)
            {
                r = r->next;
                ++currSize;
            }

            if (currSize < k)
                return head;
        
            // reverse from l to r
            ListNode* oldNext = nullptr;
            ListNode* prev = r; // l prev
            
            while(l != r)
            {
                oldNext = l->next;
                l->next = prev;
                prev = l;
                
                if (oldNext == r)
                {
                    if (!setHead)
                    {
                        head = l;
                        setHead = true;
                    }
                }

                l = oldNext;
            }

            ListNode* prLNext = prevL->next;
            prevL->next = prev;
            prevL = prLNext;
        }

        return head;
    }
};

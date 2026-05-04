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
        ListNode* prevL = nullptr;
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
            
            while(l != r) // ?
            {
                if (!prevL)
                    prevL = l;

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
                    else
                    {
                        ListNode* prLNext = prevL->next;
                        prevL->next = l;
                        prevL = prLNext;
                    }
                }

                l = oldNext;
            }
        }

        return head;
    }
};

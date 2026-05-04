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
    void reorderList(ListNode* head) 
    {
        // invers last n/2
        // l = head, r = head[n/2?+1]
        
        int n = 0;
        ListNode* curr = head;
        while (curr)
        {
            ++n;
            curr = curr->next;
        }

        int halfI = (n%2 == 0 ? n/2: n/2+1);

        // reverse all from head[halfI]
        ListNode* r = head;
        int rI = 0;
        while (rI < halfI)
        {
            r = r->next;
            ++rI;
        }

        ListNode* prevH = nullptr;
        ListNode* prevN = nullptr;
        while (r)
        {
            prevN = r->next;

            r->next = prevH;

            prevH = r;
            r = prevN;
        }
        
        // after each L place one R

        ListNode* L = head;
        ListNode* R = prevH;
        
        while (true)
        {
            ListNode* prevNL = L->next;
            L->next = R;
            L = prevNL;

            if (R == nullptr)
                break;

            ListNode* prevNR = R->next;
            R->next = L;
            R = prevNR;
        }

    }
};

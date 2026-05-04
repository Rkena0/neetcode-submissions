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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* currL1 = l1;
        ListNode* currL2 = l2;

        while (currL1 && currL2)
        {
            int currSum = currL1->val + currL2->val;
            currL2->val = currSum%10;

            if (currSum > 9)
            {
                if (currL2->next)
                    currL2->next->val++;
                else
                    currL2->next = new ListNode(1);
            }

            if (currL1->next && currL2->next == nullptr)
            {
                currL2->next = currL1->next;
                break;
            }

            currL1 = currL1->next;
            currL2 = currL2->next;
        }

        if (currL2 && currL2->val > 9)
        {
            currL2->val %= 10;
            currL2->next = new ListNode(1);
        }


        return l2;
    }
};

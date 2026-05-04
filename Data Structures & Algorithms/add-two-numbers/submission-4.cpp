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

        ListNode* res = nullptr;
        ListNode* currRes = nullptr;
        int rem = 0;
        while (currL1 || currL2 || rem)
        {
            int val1 = currL1? currL1->val: 0;
            int val2 = currL2? currL2->val: 0;
            int currSum = val1 + val2 + rem;
            int currVal = currSum%10;
            rem = currSum/10;

            if (!currRes)
            {
                currRes = new ListNode(currVal);
                res = currRes;
            }
            else
            {
                currRes->next = new ListNode(currVal);
                currRes = currRes->next;
            }
            
            currL1 = currL1? currL1->next : nullptr;
            currL2 = currL2? currL2->next : nullptr;
        }

        return res;
    }
};

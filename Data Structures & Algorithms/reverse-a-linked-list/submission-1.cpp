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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prevN = nullptr;
        ListNode* prevH = nullptr;
        
        while (head)
        {
            prevN = head->next;

            head->next = prevH;

            prevH = head;
            head = prevN;
        }

        return prevH;
    }
};

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
        // 0 -> nullptr
        // n -> prev
        if (!head)
            return nullptr;

        ListNode* prevTemp = nullptr;
        ListNode* nextTemp = nullptr;

        while (head)
        {
            nextTemp = head->next;

            head->next = prevTemp;
            
            prevTemp = head;
            head = nextTemp;
        }

        return prevTemp;        
    }
};

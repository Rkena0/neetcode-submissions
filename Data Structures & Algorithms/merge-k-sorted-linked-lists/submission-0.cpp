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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* dummy = res;

        auto pred = [](auto* lha, auto* rha)
        {
            return lha->val > rha->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(pred)> hLists;

        for (auto* currList : lists)
        {
            if (currList)
                hLists.push(currList);
        }

        while (!hLists.empty())
        {
            auto* s = hLists.top();
            //std::cout << s->val << std::endl;

            dummy->next = s;
            dummy = dummy->next;

            hLists.pop();
            if (s->next)
                hLists.push(s->next);
        }

        res = res->next;
        return res;
    }
};

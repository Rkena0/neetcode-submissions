/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head)
            return head;

        std::unordered_map<Node*, Node*> old2new;

        old2new[nullptr] = nullptr;
        
        Node* curr = head;
        while (curr)
        {
            old2new[curr] = new Node(curr->val);

            curr = curr->next;
        }

        Node* newHead = old2new[head];

        for (auto& it : old2new)
        {
            Node* oldL = it.first;
            Node* newL = it.second;

            if (oldL)
            {
                it.second->next = old2new[it.first->next];
                it.second->random = old2new[it.first->random];
            }
        }

        return newHead;
    }
};

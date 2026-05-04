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

        // // find vec of indexes for each rand, 0th el in vec is 0th in Old list
        // std::vector<int> randI;

        // headOld = head;
        // while (headOld)
        // {
        //     randI.push_back(ptr2indx[headOld->random]);

        //     headOld = headOld->next;
        // }

        // create new list
        Node* headOld = head;
        Node* newHead = new Node(headOld->val);
        Node* newList = newHead;

        headOld = headOld->next;
        while (headOld)
        {
            Node* curr = new Node(headOld->val);

            newList->next = curr;

            newList = newList->next;
            headOld = headOld->next;
        }

        // find indexes for every ptr in old list
        headOld = head;
        std::unordered_map<Node*, int> ptr2indx;

        int currI = 0;
        while (headOld)
        {
            ptr2indx[headOld] = currI;
            ++currI;

            headOld = headOld->next;
        }

        // find indx to ptr in new list
        std::unordered_map<int, Node*> indx2ptr;

        currI = 0;
        newList = newHead;
        while (newList)
        {
            indx2ptr[currI] = newList;
            ++currI;

            newList = newList->next;
        }

        // fill random for new list
        headOld = head;
        newList = newHead;

        while (newList)
        {
            if (headOld->random == nullptr)
                newList->random = nullptr;
            else
            {
                int currRandIndx = ptr2indx[headOld->random];
                Node* newPtr = indx2ptr[currRandIndx];
                newList->random = newPtr;
            }

            headOld = headOld->next;
            newList = newList->next;
        }

        return newHead;        
    }
};

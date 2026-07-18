class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // t1 == t2 pop both
        // pop t1, t2 push t1-t2

        std::priority_queue<int> heap(stones.begin(), stones.end());

        while (heap.size() > 1)
        {
            int top1 = heap.top();
            heap.pop();
            int top2 = heap.top();
            heap.pop();

            int diff = top1-top2;
            if (diff)
                heap.push(diff);
        }

        if (heap.size() > 0)
            return heap.top();
        
        return 0;        
    }
};

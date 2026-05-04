class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // Because one number is duplicated, 
        // two indices will point into the same chain, 
        // creating a cycle — exactly like a linked list with a loop.
        // why?
        // because there are 3 ways to point to some index
        // 1. before reaching indx: nums[0] -> 4
        // 2. after reaching indx: nums[0] -> 4 -> 3 -> 4
        // 3. the indx poitns to itself: nums[4] -> 4
        // if we have 3th case there is definitely a cycle but also we need to somehow reach the index, 
        // so if there is only one index then no one will point to it in this cstatic_assert
        // if we have only 1th or 2nd case, there is no cycle
        // + if there is duplicate indx, we have cycle because we reach the index and then return to it
        // also the start of the cycle is the duplicate index

        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while (slow != fast);

        int slow2 = 0;
        while (slow != slow2)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};

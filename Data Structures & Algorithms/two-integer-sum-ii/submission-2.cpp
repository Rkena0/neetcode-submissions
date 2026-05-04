class Solution {
public:
    int binarySearch(vector<int>& numbers, int toFind, int startIndx)
    {
        int l = startIndx+1;
        int r = numbers.size()-1;

        while (l <= r)
        {
            int m = (l+r)/2;

            if (numbers[m] == toFind)
                return m;
    
            if (l == r)
                return -1;
    
            if (numbers[m] > toFind)
                r = m;
            else
                l = m+1;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for (int i = 0; i < numbers.size(); ++i)
        {
            int curr = numbers[i];
            int toFind = target - curr;

            int res = binarySearch(numbers, toFind, i);

            if (res != -1)
                return {i+1, res+1};
        }

        return {-1}; 
    }
};

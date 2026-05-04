class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix[0].size();
        int m = matrix.size();

        int l = 0;
        int r = m-1;

        int candM = -1;
        while (l <= r)
        {
            int mid = (r+l)/2;
            std::cout << "candM: " << mid << std::endl;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1])
            {
                candM = mid;
                break;
            }

            if (target < matrix[mid][0])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (candM == -1)
        {
            return false;
        }

        l = 0;
        r = n-1;
        while (l <= r)
        {
            int mid = (r+l)/2;

            if (matrix[candM][mid] == target)
                return true;
            
            if (target < matrix[candM][mid])
            {
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }

        return false;        
    }
};

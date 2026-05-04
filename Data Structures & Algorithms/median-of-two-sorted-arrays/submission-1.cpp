class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) 
    {
        if (A.size() > B.size())
            std::swap(A, B);
        
        if (A.size() == 0 && B.size() == 0)
            return 0.0;
        
        if (A.size() == 0)
        {
            if (B.size() % 2 == 0)
            {
                std::cout << B[B.size()/2 - 1] << " " << B[B.size()/2] << std::endl;
                return (B[B.size()/2 - 1] + B[B.size()/2]) / 2.0;
            }

            return B[B.size()/2];
        }

        int halfCount = (A.size() + B.size()) / 2;

        int l = 0;
        int r = A.size();

        while (l <= r)
        {
            int count = (l+r)/2;

            int maxAPart = count-1; 
            int maxBPart = halfCount-count-1;

            if (maxAPart >= 0 && A[maxAPart] > B[maxBPart+1])
            {
                r = count - 1;
            }
            else if (maxBPart >= 0 && B[maxBPart] > A[maxAPart+1])
            {
                l = count + 1;
            }
            else
            {
                int next;
                if (maxAPart == A.size()-1)
                    next = B[0];
                else if (maxBPart == B.size()-1)
                    next = A[0];
                else
                    next = std::min(A[maxAPart+1], B[maxBPart+1]);

                if ((A.size() + B.size()) % 2 == 0)
                {
                    int curr = std::max(A[maxAPart], B[maxBPart]);
                    
                    return (curr + next) / 2.0;
                }

                return next;
            }
        }

        return 0;
    }
};

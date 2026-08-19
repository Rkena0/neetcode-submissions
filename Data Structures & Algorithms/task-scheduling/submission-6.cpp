class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int res = 0;

        std::vector<int> letter_freq(26);

        for (auto &ch : tasks)
        {
            ++letter_freq[ch - 'A'];
        }

        std::list<int> freq_letter;
        for (int i = 0; i < letter_freq.size(); ++i)
        {
            if (letter_freq[i] == 0)
                continue;

            freq_letter.push_back(letter_freq[i]);
        }

        freq_letter.sort(std::greater<int>());

        while (!freq_letter.empty())
        {
            int &max_freq = freq_letter.front();
                        
            if (max_freq == 1)
            {
                res += freq_letter.size();
                break;
            }
            // == 1
            // just add rest 
            // > 1
            // --cand -> --one per char before n
            // max count for one letter          
                                    
            ++res;
            --max_freq;
            // from second biggest
            int limit = n;
            for (auto it = ++freq_letter.begin(); it != freq_letter.end() && limit; ++it)
            {   
                int &curr_freq = *it;
                
                --limit;
                --curr_freq;
                ++res;
                                
                if (curr_freq == 0)
                {
                    it = freq_letter.erase(it);
                    --it;
                }              
            }
           
            //std::cout << "before " << "res: " << res << std::endl; 
            if (limit > 0)
            {
                res += limit;
            }
            
            //std::cout << "after " << "res: " << res << std::endl;              

            freq_letter.sort(std::greater<int>());  
        }

        return res;        
    }
};

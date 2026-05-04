class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // row
        for (int i = 0; i < board.size(); ++i)
        {
            std::unordered_set<char> duplicate;
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;

                if (duplicate.count(board[i][j]) > 0)
                    return false;
            
                duplicate.insert(board[i][j]);
            }
        }

        // collumn
        for (int i = 0; i < board.size(); ++i)
        {
            std::unordered_set<char> duplicate;
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[j][i] == '.')
                    continue;
                
                if (duplicate.count(board[j][i]) > 0)
                    return false;
            
                duplicate.insert(board[j][i]);
            }
        }
        
        // 3x3   
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board[i].size(); j += 3)
            {
                std::unordered_set<char> duplicate;
                for (int k = i; k < i+3; ++k)
                {
                    for (int l = j; l < j+3; ++l)
                    {
                        if (board[k][l] == '.')
                            continue;

                        if (duplicate.count(board[k][l]) > 0)
                            return false;
                    
                        duplicate.insert(board[k][l]);
                    }
                }
            }
        }

        return true;
    }
};

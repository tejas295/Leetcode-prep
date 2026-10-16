class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n =board.size();
        for(int i = 0; i < n; i++) {
            vector<int> freq(9, 0);
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') continue;
                int idx = board[i][j] - '1';
                if(freq[idx] == 0) {
                freq[idx] = 1;
                }
                else {
                    return false;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            vector<int> freq(9, 0);
            for(int j = 0; j < n; j++) {
                if(board[j][i] == '.') continue;
                int idx = board[j][i] - '1';
                if(freq[idx] == 0) {
                freq[idx] = 1;
                }
                else {
                    return false;
                }
            }
        }
        for(int i = 0; i < n; i += 3) {
            for(int j = 0; j < n; j += 3) {
                vector<int> freq(9, 0);
                for(int r = i; r < i+3; r++) {
                    for(int c = j; c < j+3; c++) {
                        if(board[r][c] == '.') continue;
                        int idx = board[r][c] - '1';
                        if(freq[idx] == 0) {
                        freq[idx] = 1;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
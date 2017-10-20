/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
*/

// a naive solution:

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // line check
        for (int i = 0; i < 9; ++i) {
            int flag = 0;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                if (((1 << (board[i][j] - '0')) & flag) != 0) {
                    return false;
                }
                flag |= (1 << (board[i][j] - '0'));
            }
        }
        // row check
        for (int i = 0; i < 9; ++i) {
            int flag = 0;
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.')
                    continue;
                if (((1 << (board[j][i] - '0')) & flag) != 0) {
                    return false;
                }
                flag |= (1 << (board[j][i] - '0'));
            }
        }
        // block check
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int flag = 0;
                for (int ii = i; ii < i + 3; ++ii) {
                    for (int jj = j; jj < j + 3; ++jj) {
                        if (board[ii][jj] == '.')
                            continue;
                        if (((1 << (board[ii][jj] - '0')) & flag) != 0) {
                            return false;
                        }
                        flag |= (1 << (board[ii][jj] - '0'));
                    }
                }
            }
        }
        return true;
    }
};

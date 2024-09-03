class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool columns[9][9] = {false};
        bool squares[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int squareIndex = (i / 3) * 3 + (j / 3);

                    if (rows[i][num] || columns[j][num] || squares[squareIndex][num]) {
                        return false;
                    }

                    rows[i][num] = true;
                    columns[j][num] = true;
                    squares[squareIndex][num] = true;
                }
            }
        }

        return true;
    }
};

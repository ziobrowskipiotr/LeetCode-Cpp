class Solution {
public:
    bool rows_posibility(vector<vector<char>>& board){
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> squares;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board.at(i).at(j) == '.'){
                    continue;
                }
                else{
                    if(rows[i].count(board.at(i).at(j)) == 0){
                        rows[i].emplace(board.at(i).at(j));
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool columns_posibility(vector<vector<char>>& board){
        unordered_map<int, unordered_set<char>> columns;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board.at(j).at(i) == '.'){
                    continue;
                }
                else{
                    if(columns[j].count(board.at(j).at(i)) == 0){
                        columns[j].emplace(board.at(j).at(i));
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }

    struct PairHash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    bool squares_posibility(vector<vector<char>>& board) {
        unordered_map<pair<int, int>, unordered_set<char>, PairHash> squares;
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char currentChar = board[i][j];
                if (currentChar == '.') {
                    continue;
                }

                // Sprawdzenie rzędu
                if (rows[i].count(currentChar) > 0) {
                    return false;
                } else {
                    rows[i].emplace(currentChar);
                }

                // Sprawdzenie kolumny
                if (columns[j].count(currentChar) > 0) {
                    return false;
                } else {
                    columns[j].emplace(currentChar);
                }

                // Sprawdzenie kwadratu 3x3
                pair<int, int> squareIndex = {i / 3, j / 3};
                if (squares[squareIndex].count(currentChar) > 0) {
                    return false;
                } else {
                    squares[squareIndex].emplace(currentChar);
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        bool result1 = rows_posibility(board);
        bool result2 = columns_posibility(board);
        bool result3 = squares_posibility(board);

        return result1 && result2 && result3;
    }
};
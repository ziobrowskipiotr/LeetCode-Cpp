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

    bool squares_posibility(vector<vector<char>>& board){
        unordered_map<int, unordered_set<char>> squares;
        int rows = 3;
        int columns = 3;
        int j = 0;
        int k = 0;
        for(int i=0; i<9; i++){
            while(j<rows){
                while(k<columns){
                    if(board.at(j).at(k) == '.'){
                        continue;
                    }
                    else{
                        if(squares[i].count(board.at(j).at(k)) == 0){
                            squares[i].emplace(board.at(j).at(k));
                        }
                        else{
                            return false;
                        }
                    }
                    k++;
                }
                j++;
                columns += 3;
            }
            rows += 3;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        bool result1 = rows_posibility(board);
        bool result2 = columns_posibility(board);

        return result1 && result2;
    }
};
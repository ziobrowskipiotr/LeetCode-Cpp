class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> columns;
        std::unordered_map<int, std::unordered_set<char>> squares;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board.at(i).at(j) != '.'){
                    if(rows[i].count(board.at(i).at(j)) == 0){
                        rows[i].emplace(board.at(i).at(j));
                        if(columns[j].count(board.at(i).at(j)) == 0){
                            columns[j].emplace(board.at(i).at(j));
                            if(squares[(i/3)*3 + j/3].count(board.at(i).at(j)) == 0){
                                squares[(i/3)*3 + j/3].emplace(board.at(i).at(j));
                            }
                            else{
                                return false;
                            }
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
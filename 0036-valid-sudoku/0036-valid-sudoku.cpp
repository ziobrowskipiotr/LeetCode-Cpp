//
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> columns;
        std::unordered_map<int, std::unordered_set<char>> squares;
        char num;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                num = board.at(i).at(j);
                if(num != '.'){
                    if(rows[i].count(num) == 0 &&
                    columns[j].count(num) == 0 && 
                    squares[(i/3)*3 + j/3].count(num) == 0){
                        rows[i].emplace(num);
                        columns[j].emplace(num);
                        squares[(i/3)*3 + j/3].emplace(num);
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
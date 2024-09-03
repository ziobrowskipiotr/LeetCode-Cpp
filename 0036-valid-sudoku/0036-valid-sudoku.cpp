class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool columns[9][9] = {false};
        bool squares[9][9] = {false};
        char num;
        int val;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                num = board.at(i).at(j);
                if(num != '.'){
                    val = (int)(num - '1');
                    cout<<val<<endl;
                    if(rows[i][val] || columns[j][val] || squares[3*(i/3)+j/3][val]){
                        return false;
                    }
                    else{
                        rows[i][val] = true;
                        columns[j][val] = true;
                        squares[3*(i/3)+j/3][val] = true;
                    }
                }
            }
        }
        return true;
    }
};
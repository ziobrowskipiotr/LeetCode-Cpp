class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        std::string* tablica = new std::string[numRows];
        std::string result;
        
        tablica[0]+=s[0];
        int j = 0;
        for(int i=1; i<s.size(); i++){
            if(((i-1)/(numRows-1))%2 == 0){
                j++;
                tablica[j] += s[i];
            }
            else{
                j--;
                tablica[j] += s[i];
            }
        }
        for(int i=0; i<numRows; i++){
            result+=tablica[i];
        }
        delete[] tablica;
        return result;
    }
};
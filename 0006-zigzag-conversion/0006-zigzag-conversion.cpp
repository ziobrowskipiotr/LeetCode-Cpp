class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        std::vector<std::string> wektor(numRows, "");
        std::string result;
        wektor[0]+=s[0];
        int j = 0;

        for(int i=1; i<s.size(); i++){
            if(((i-1)/(numRows-1))%2 == 0){
                j++;
                wektor.at(j) += s[i];
            }
            else{
                j--;
                wektor.at(j) += s[i];
            }
        }
        for(int i=0; i<wektor.size(); i++){
            result+=wektor[i];
        }
        return result;
    }
};
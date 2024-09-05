class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> stos;
        std::string word;
        int siz = s.size();
        int j = 0;
        for(int i=0; i<siz; i++){
            if(s[i] == ' '){
            }
            else{
                j = i;
                while(j<siz && s[j] != ' '){
                    j++;
                }
                stos.push_back(s.substr(i,j-i));
                i = j;
            }
        }
        for(int i=stos.size()-1; i>=0; i--){
            word += stos.at(i)+" ";
        }
        return word.substr(0, word.size()-1);
    }
};
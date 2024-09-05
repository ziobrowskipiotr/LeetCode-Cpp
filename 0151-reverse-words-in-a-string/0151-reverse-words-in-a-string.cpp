//
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
            s += stos.at(i)+" ";
        }
        return s.substr(siz, s.size()-siz-1);
    }
};
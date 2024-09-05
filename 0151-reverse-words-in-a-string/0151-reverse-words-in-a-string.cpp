class Solution {
public:
    string reverseWords(string s) {
        std::stack<std::string> stos;
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
                stos.push(s.substr(i,j-i));
                i = j;
            }
        }
        while(!stos.empty()){
            word += stos.top()+" ";
            stos.pop();
        }
        return word.substr(0, word.size()-1);
    }
};
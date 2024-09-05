class Solution {
public:
    string reverseWords(string s) {
        std::stack<std::string> stos;
        std::string word;
        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
            }
            else{
                j = i;
                while(j<s.size() && s[j] != ' '){
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
class Solution {
public:
    string reverseWords(string s) {
        std::stack<std::string> stos;
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
        s = "";
        while(!stos.empty()){
            s += stos.top()+" ";
            stos.pop();
        }
        return s.substr(0, s.size()-1);
    }
};
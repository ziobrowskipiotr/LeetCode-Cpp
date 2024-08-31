class Solution {
public:
    int j = 0;
    int p = 0;
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> mapa;
        std::unordered_map<std::string, char> mapa1;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' '){
                if(mapa.count(pattern[p]) == 0 && mapa1.count(s.substr(j,i-j)) == 0){
                    mapa[pattern[p]] = s.substr(j,i-j);
                    mapa1[s.substr(j,i-j)] = pattern[p];
                    j = i+1;
                    p++;
                }
                else if(mapa[pattern[p]] == s.substr(j,i-j)){
                    j = i+1;
                    p++;
                }
                else{
                    return false;
                }
            }
            else if(i == s.length()-1){
                if(mapa.count(pattern[p]) == 0 && mapa1.count(s.substr(j,i-j+1)) == 0){
                    continue;
                }
                else if(mapa[pattern[p]] == s.substr(j, i-j+1)){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(p == pattern.length()-1){
            return true;
        }
        else{
            return false;
        }
    }
};
//
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> mapa;
        std::unordered_map<char, char> reverse_mapa;
        for(int i=0; i<s.length(); i++){
            if(mapa.count(s[i]) == 0 && reverse_mapa.count(t[i]) == 0){
                mapa[s[i]] = t[i];
                reverse_mapa[t[i]] = s[i];
            }
            else if(mapa.count(s[i]) == 0 && reverse_mapa.count(t[i]) != 0){
                return false;
            }
            else if(mapa[s[i]] == t[i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
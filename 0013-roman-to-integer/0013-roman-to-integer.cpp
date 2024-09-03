//
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        std::unordered_map<char, int> mapa = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };
        for(int i=s.size()-1; i>0; i--){
            if(s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')){
                result -= 2;
            }
            else if(s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')){
                result -= 20;
            }
            else if(s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')){
                result -= 200;
            }
            result += mapa[s[i]];
        }
        result += mapa[s[0]];
        return result;
    }
};
//
class Solution {
public:
    string intToRoman(int num) {
        int i_tab[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        std::string s_tab[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int temp = 0;
        std::string result;
        for(int i=0; i<13; i++){
            temp = i_tab[i];
            i_tab[i] = num / i_tab[i];
            for(int j=0; j<i_tab[i]; j++){
                result += s_tab[i];
            }
            num -= i_tab[i] * temp;
        }
        return result;
    }
};
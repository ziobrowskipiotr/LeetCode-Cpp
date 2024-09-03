class Solution {
public:
    string intToRoman(int num) {
        int i_tab[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        std::string s_tab[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int* p1 = i_tab;
        std::string* p2 = s_tab;
        int temp = 0;
        std::string result;
        for(int i=0; i<13; i++){
            temp = *p1;
            *p1 = num / *p1;
            for(int j=0; j<*p1; j++){
                result += *p2;
            }
            num -= *p1 * temp;
            p1++;
            p2++;
        }
        return result;
    }
};
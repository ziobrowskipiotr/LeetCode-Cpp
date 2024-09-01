class Solution {
public:
    bool isHappy(int n) {
        int value = n;
        int result;
        const int zero = (int)'0';
        std::string s_value;
        std::unordered_map<int, int> hashmap;
        while(value != 1){
            if(hashmap.count(value) == 0){
                s_value = std::to_string(value);
                hashmap[value] = [](std::string& num, int& res, const int& zer) -> int{
                    res = 0;
                    for(int i=0; i<num.size(); i++){
                        res += ((int)num[i] - zer) * ((int)num[i] - zer);
                    }
                    return res;
                }(s_value, result, zero);
                value = result;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
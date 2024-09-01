class Solution {
public:
    bool isHappy(int n) {
        int value = n;
        int result;
        int data;
        std::unordered_map<int, int> hashmap;
        while(value != 1){
            if(hashmap.count(value) == 0){
                result = 0;
                data = value;
                while(data != 0){
                    result += (data%10) * (data%10);
                    data /= 10;
                }
                hashmap[value] = result;
                value = result;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
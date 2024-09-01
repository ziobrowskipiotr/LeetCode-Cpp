class Solution {
public:
    bool isHappy(int n) {
        int result;
        int data;
        std::unordered_map<int, int> hashmap;
        while(n != 1){
            if(hashmap.count(n) == 0){
                result = 0;
                data = n;
                while(data != 0){
                    result += (data%10) * (data%10);
                    data /= 10;
                }
                hashmap[n] = result;
                n = result;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
//
class Solution {
public:
    bool isHappy(int n) {
        int* result = new int(0);
        int* data = new int(n);
        std::unordered_map<int, int> hashmap;
        while(n != 1){
            if(hashmap.count(n) == 0){
                while(*data != 0){
                    *result += (*data%10) * (*data%10);
                    *data /= 10;
                }
                hashmap[n] = *result;
                n = *result;
                *result = 0;
                *data = n;
            }
            else{
                delete result;
                delete data;
                return false;
            }
        }
        delete result;
        delete data;
        return true;
    }
};
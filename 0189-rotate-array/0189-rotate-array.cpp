//
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::vector<int> temp(nums.end()-k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
        for(int i=0; i<k; i++){
            nums.pop_back();
        }
    }
};
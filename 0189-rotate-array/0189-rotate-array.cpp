class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::vector<int> temp(nums.end()-k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
        nums.erase(nums.end() - k, nums.end());
    }
};
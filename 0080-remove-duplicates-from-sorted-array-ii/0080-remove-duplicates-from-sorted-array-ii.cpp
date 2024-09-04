//2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        int k=2;
        for(int i=2; i<nums.size(); i++){
            if(nums[k-2] != nums[i]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
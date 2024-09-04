class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3){
            return nums.size();
        }
        std::vector<int>::iterator it1 = nums.begin();
        std::vector<int>::iterator it2 = it1+1;
        std::vector<int>::iterator it3 = it2+1;
        while(it3 != nums.end()){
            if(*it1 == *it2 && *it1 == *it3){
                cout<<"it1: "<<*it1<<endl;
                cout<<"it2: "<<*it2<<endl;
                cout<<"it3: "<<*it3<<endl;
                nums.erase(it3);
            }
            else{
                cout<<"it1: "<<*it1<<endl;
                cout<<"it2: "<<*it2<<endl;
                cout<<"it3: "<<*it3<<endl;
                it1++;
                it2++;
                it3++;
            }
        }
        return nums.size();
    }
};
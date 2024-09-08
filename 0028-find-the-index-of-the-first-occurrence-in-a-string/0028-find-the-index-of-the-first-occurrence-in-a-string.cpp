class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_size = haystack.size();
        int ned_size = needle.size();
        int pointer1;
        int pointer2;

        for(int i=0; i<hay_size; i++){
            if(haystack[i] == needle[0]){
                pointer1=0;
                pointer2=i;
            }
            while(pointer2<hay_size && (haystack[pointer2] == needle[pointer1])){
                if(pointer1 == ned_size-1){
                    return i;
                }
                pointer1++;
                pointer2++;
            }
        }
        return -1;
    }
};
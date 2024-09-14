class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1<<31;
        uint32_t point = 1;
        uint32_t g = n & mask;
        cout<<g<<endl;
        for(int i=0; i<16; i++){
            if(n & mask){
                if(!(n & point)){
                    n = n ^ point;
                    n = n ^ mask;
                }
            }
            else{
                if(n & point){
                    n = n ^ point;
                    n = n ^ mask;
                }
            }
            mask = mask>>1;
            point = point<<1;
        }
        return n;
    }
};
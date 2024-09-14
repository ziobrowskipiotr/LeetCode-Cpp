class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1<<31;
        uint32_t point = 1;
        bool bol1;
        bool bol2;

        for(int i=0; i<16; i++){
            bol1 = n & point;
            bol2 = n & mask;
            if(bol1 != bol2){
                n = n ^ point;
                n = n ^ mask;
            }
            mask = mask>>1;
            point = point<<1;
        }
        return n;
    }
};
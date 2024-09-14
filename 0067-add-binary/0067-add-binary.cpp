class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()){
            b.insert(b.begin(), a.length()-b.length(),'0');
        }
        else{
            a.insert(a.begin(), b.length()-a.length(),'0');
        }
        int* a_len = new int(a.length());
        bool temp = false;
        char* point1 = &a[*a_len-1];
        char* point2 = &b[*a_len-1];
        std::string result(*a_len+1, '\0');
        for(int i=*a_len; i>0; i--){
            if((int)*point1-'0' ^ (int)*point2-'0'){
                if(temp){
                    result[i] = '0';
                }
                else{
                    result[i] = '1';
                }
            }
            else{
                if(temp){
                    result[i] = '1';
                }
                else{
                    result[i] = '0';
                }
            }
            temp = ((int)*point1-'0' & (int)*point2-'0') ^ (((int)*point1-'0' ^ (int)*point2-'0') & temp);
            point1--;
            point2--;
        }
        if(temp){
            result[0] = '1';
        }
        else{
            result.erase(result.begin());
        }
        delete a_len;
        return result;
    }
};
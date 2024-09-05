class Solution {
public:
    string reverseWords(string s) {
        std::istringstream iss(s);
        std::vector<std::string> wektor;
        std::string slowo;
        while(iss >> slowo){
            wektor.emplace(wektor.begin(), slowo);
        }
        slowo = "";
        for(int i=0; i<wektor.size(); i++){
            slowo += wektor[i]+" ";
        }
        return slowo.substr(0, slowo.size()-1);
    }
};
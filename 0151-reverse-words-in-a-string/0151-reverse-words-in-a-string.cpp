class Solution {
public:
    string reverseWords(string s) {
        std::istringstream iss(s);
        std::ostringstream oss;
        std::vector<std::string> wektor;
        std::string slowo;
        while(iss >> slowo){
            wektor.emplace(wektor.begin(), slowo);
        }
        for(auto& word : wektor){
            oss << word << " ";
        }
        slowo = oss.str();
        slowo = slowo.substr(0, slowo.size()-1);
        return slowo;
    }
};
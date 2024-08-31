//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> global_wektor;
        std::unordered_map<std::string, std::vector<string>> global_mapa;
        std::string* ptr = new std::string;

        for(const auto& word : strs){
            *ptr = word;
            sort(ptr->begin(), ptr->end());
            global_mapa[*ptr].push_back(word);
        }
        delete ptr;
        for(const auto& [word, wektor] : global_mapa){
            global_wektor.push_back(wektor);
        }
        return global_wektor;
    }
};
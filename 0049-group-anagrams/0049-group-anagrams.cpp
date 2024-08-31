class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> global_wektor;
        std::unordered_map<std::string, std::vector<string>> global_mapa;
        std::unordered_map<char, int> mapa;
        std::string ptr;

        for(const auto& word : strs){
            ptr = word;
            sort(ptr.begin(), ptr.end());
            global_mapa[ptr].push_back(word);
        }
        for(const auto& [word, wektor] : global_mapa){
            global_wektor.push_back(wektor);
        }
        return global_wektor;
    }
};
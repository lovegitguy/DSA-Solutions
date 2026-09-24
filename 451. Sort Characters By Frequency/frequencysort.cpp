class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frequency;
        
        for(char c : s) {
            frequency[c]++;
        }

        vector<pair<char, int>> characters;

        for(auto it : frequency) {
            characters.push_back(it);
        }

        sort(characters.begin(), characters.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string answer;

        for(auto it : characters) {
            answer.append(it.second, it.first);
        }

        return answer;
    }
};
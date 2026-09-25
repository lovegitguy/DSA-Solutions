class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> frequency;

        if(s.length() != t.length()){
            return false;
        }

        for(char c : s){
            frequency[c]++;
        }

        for(char c : t){
            frequency[c]--;
        }

        for(auto pair : frequency){
            if(pair.second != 0){
                return false;
            }
        }

        return true;
    }
};
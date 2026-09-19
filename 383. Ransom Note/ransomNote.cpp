class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> s;

        for(char m : magazine) {
            s[m]++;
        }

        for(char r : ransomNote) {
            auto it = s.find(r);

            if(it == s.end() || it->second == 0) {
                return false;
            }

            s[r]--;
        }

        return true;
    }
};
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> answer;

        int common[26];

        for(int i = 0; i < 26; i++) {
            common[i] = 100;
        }

        for(string word : words) {
            int count[26] = {};

            for(char c : word) {
                count[c - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                common[i] = min(common[i], count[i]);
            }
        }

        for(int i = 0; i < 26; i++) {
            while(common[i] > 0) {
                string letter(1, 'a' + i);
                answer.push_back(letter);
                common[i]--;
            }
        }

        return answer;
    }
};
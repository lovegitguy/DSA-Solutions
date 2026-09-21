class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> patterntoWord;
        map<string, char> wordtoPattern;

        stringstream ss(s);
        string word;

        for(int i = 0; i < pattern.size(); i++) {
            if(!(ss >> word)) {
                return false;
            }

            if(patterntoWord.find(pattern[i]) != patterntoWord.end()
               && patterntoWord[pattern[i]] != word) {
                return false;
            }

            if(wordtoPattern.find(word) != wordtoPattern.end()
               && wordtoPattern[word] != pattern[i]) {
                return false;
            }

            patterntoWord[pattern[i]] = word;
            wordtoPattern[word] = pattern[i];
        }

        if(ss >> word) {
            return false;
        }

        return true;
    }
};


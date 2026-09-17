class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
            string morse[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
    };

    for(string word:words){
        string combined="";
        for(char c:word){
            string morsequivalent=morse[c-'a'];
            combined+=morsequivalent;
        }
        
        s.insert(combined);
    }
     return s.size();
    }
};
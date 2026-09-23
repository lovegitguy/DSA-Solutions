class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string>>  groups;

        for(string word:strs){
            string sortedWord=word;
            sort(sortedWord.begin(),sortedWord.end());
            groups[sortedWord].push_back(word);
        }

        vector<vector<string>> answer;

         for(auto group : groups){
            answer.push_back(group.second);
        }

        return answer;
    }
};
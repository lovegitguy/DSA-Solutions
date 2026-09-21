class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    map<char, int> frequency;
  
    for(char m:magazine){
        frequency[m]++;
    }

    for(char c:ransomNote){

        if(frequency[c]<=0){
            return false;
        }
        frequency[c]--;
    }

    return true;
    }

};
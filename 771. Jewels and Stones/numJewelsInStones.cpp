class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s;
        int count=0;

        for(char a:jewels){
            s.insert(a);
        }
        

        for(char c:stones){
            if(s.find(c)!=s.end()){
                count++;
            }
        }
        return count;
    } 
};
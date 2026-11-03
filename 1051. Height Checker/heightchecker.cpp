class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> answer = heights;

        sort(answer.begin(), answer.end());

        for(auto i:heights){
            answer.push_back(i);
        }
        int numberOfIndices = 0;

        for(int i =0 ; i < heights.size(); i++){
            
            if(heights[i]!=answer[i]){
                numberOfIndices++;
            }
        }

        return numberOfIndices;
    }
};
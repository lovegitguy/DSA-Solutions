class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;

        for(int n:nums){
            answer.push_back(n*n);
        }

        sort(answer.begin(),answer.end());
        return answer;
    }
};
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        vector<int> answer;
    
        for(int i =0;i<accounts.size();i++){
            int sum=0;
            for(int j=0;j<accounts[i].size();j++){
                sum +=accounts[i][j];
            }
            answer.push_back(sum);
        }
        int max_val = *max_element(answer.begin(), answer.end());
        return max_val;
    }
};
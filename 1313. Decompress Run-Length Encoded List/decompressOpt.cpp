class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> answer;
             int n=nums.size();
        for(int i = 0;i<n-1;i+=2){
                int v=nums[i+1];
                int m=nums[i];
            for(int j=1;j<=m;j++)
            {
                answer.push_back(v);
            }
        }

     return answer;
    }
};
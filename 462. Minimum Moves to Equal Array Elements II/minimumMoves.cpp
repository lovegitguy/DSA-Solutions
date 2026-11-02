class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=0;i<nums.size();i++){
           int target=nums[nums.size()/2];

            moves+=abs(nums[i]-target);
        }

        return moves;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int  moves=0;

        for(int i =0 ;i<nums.size();i++){
            int target=nums[nums.size()-1];
            moves+=abs(target-nums[i]);
        }

        return moves;
    }
};
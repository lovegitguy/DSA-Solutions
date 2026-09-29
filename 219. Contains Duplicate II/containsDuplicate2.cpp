class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for(int i = 0;i<nums.size();i++){
         
            if(lastIndex.find(nums[i])!=lastIndex.end()){
                int previousIndex=lastIndex[nums[i]];
                if(abs(i-previousIndex<=k))
                {
                    return true;
                }
            }
            
            lastIndex[nums[i]]=i;
        }
        return false;
    }
};
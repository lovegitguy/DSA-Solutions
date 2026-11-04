class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> answer;
        for(int i =0 ;i<nums.size();i++){
            int index = abs(nums[i]) - 1;
            if(nums[index]>0){
                nums[index]=-nums[index];
            }
        }

        for(int j=0;j<nums.size();j++){
            
            if(nums[j]>0){
                answer.push_back(j+1);
            }
        }
    return answer;
    }
};
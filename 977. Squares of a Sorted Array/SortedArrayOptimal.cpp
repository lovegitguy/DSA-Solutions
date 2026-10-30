class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());
        int left =0;
        int right =nums.size()-1;
        int k= nums.size()-1;

        while(left<=right){
            if(nums[left]*nums[left]>nums[right]*nums[right]){
                answer[k] = nums[left] * nums[left];
                left++;
            }

            else{
                answer[k] = nums[right] * nums[right];
                right--;
            }
            k--;
        }

        return answer;
    }
};
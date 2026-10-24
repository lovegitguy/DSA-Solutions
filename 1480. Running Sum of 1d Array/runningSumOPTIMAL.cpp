
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer;

        answer.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int sum = nums[i] + answer[i - 1];
            answer.push_back(sum);
        }

        return answer;
    }
};
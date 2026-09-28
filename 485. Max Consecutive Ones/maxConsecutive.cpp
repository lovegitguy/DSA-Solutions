class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int answer = 0;

        for(int n : nums) {
            if(n == 1) {
                current++;
                answer = max(answer, current);
            }
            else {
                current = 0;
            }
        }

        return answer;
    }
};
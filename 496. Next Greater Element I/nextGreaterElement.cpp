class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greater;
        stack<int> st;

        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                greater[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        while(!st.empty()) {
            greater[st.top()] = -1;
            st.pop();
        }

        vector<int> answer;

        for(int num : nums1) {
            answer.push_back(greater[num]);
        }

        return answer;
    }
};
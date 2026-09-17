class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> ans;
        vector<int> answer;

        for(int n : nums1)
        {
            ans.insert(n);
        }

        for(int n2 : nums2)
        {
            if(ans.find(n2) != ans.end())
            {
                if(find(answer.begin(), answer.end(), n2) == answer.end())
                {
                    answer.push_back(n2);
                }
            }
        }

        return answer;
    }
};
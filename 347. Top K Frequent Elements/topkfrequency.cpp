class Solution {
public:

   static bool largestFrequency(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> frequency;
        vector<pair<int,int>> elements;
        vector<int> answer;

        for(int n : nums) {
            frequency[n]++;
        }

        for(auto n : frequency) {
            elements.push_back({n.first, n.second});
        }

        sort(elements.begin(), elements.end(), largestFrequency);

        for(int i = 0; i < k; i++) {
            answer.push_back(elements[i].first);
        }

        return answer;
    }
};
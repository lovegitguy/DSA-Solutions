class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        set<int> occurrences;

        for (int n : arr) {
            frequency[n]++;
        }

        for (auto x : frequency) {
            if (occurrences.find(x.second) != occurrences.end()) {
                return false;
            }

            occurrences.insert(x.second);
        }

        return true;
    }
};
class Solution {
public:
     static bool largestFrequency(pair<string,int> a, pair<string,int> b) {
        if(a.second!=b.second){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> frequency;
        vector<pair<string, int>> elements;
        vector<string> answer;

        for(string c:words){
            frequency[c]++;
        }

        for (auto n : frequency){
            elements.push_back({n.first, n.second});
        }

        sort(elements.begin(), elements.end(), largestFrequency);

         for(int i = 0; i < k; i++) {
            answer.push_back(elements[i].first);
        }
        return answer;
    }
};
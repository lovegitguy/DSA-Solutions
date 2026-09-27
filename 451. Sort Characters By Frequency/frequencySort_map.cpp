class Solution {
public:
    
   static bool largestFrequency(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char, int> frequency;
        vector<pair<char, int>>elements;
        string answer="";

        for(char c: s){
            frequency[c]++;
        }

           for(auto n : frequency) {
            elements.push_back({n.first, n.second});
        }
        
        sort(elements.begin(), elements.end(), largestFrequency);
        for(auto element : elements) {
        for(int i = 0; i < element.second; i++) {
            answer += element.first;
        }
        }
        return answer;   
    }
};
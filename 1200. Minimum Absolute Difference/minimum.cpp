class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> answer;

        sort(arr.begin(), arr.end());
        int minDiff= INT_MAX;

        for(int i = 0; i<arr.size()-1 ; i++)
        {
            int diff=arr[i+1]-arr[i];

            if(diff<minDiff){
                minDiff=diff; 
                answer.clear();
            }  

            if(diff==minDiff){
                answer.push_back({arr[i],arr[i+1]});
            }
        }

        return answer;
    }
};
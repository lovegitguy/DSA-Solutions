class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i =0;i<numRows;i++){
            vector<int> row(i + 1, 1);
            for(int j=1;j<i;j++){
                row[j] = answer[i-1][j-1] + answer[i-1][j];
            }
            answer.push_back(row);
        }
        return answer;
    }
};

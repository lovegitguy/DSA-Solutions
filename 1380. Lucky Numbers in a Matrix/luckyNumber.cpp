
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMins(m, INT_MAX);
        vector<int> colMax(n, INT_MIN);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowMins[i] = min(rowMins[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        vector<int> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == rowMins[i] &&
                   matrix[i][j] == colMax[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        if(mat.size()*mat[0].size()!=r*c){
            return mat;
        }

        vector<vector<int> >result(r, vector<int> (c));

        int k=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){    
               result[k / c][k % c] = mat[i][j];
                k++;
            }
          
        }
        return result;
    }
};
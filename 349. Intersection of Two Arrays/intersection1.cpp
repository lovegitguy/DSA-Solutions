class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            bool founddigit=false;

            for(int k=0;k<i;k++){
                if(nums1[i]==nums1[k]){
                    founddigit=true;
                    break;
                }
            }
                if(founddigit){
                    continue;
                }

              for (int j = 0; j < nums2.size(); j++) {
                 if (nums1[i] == nums2[j]) {
                     ans.push_back(nums1[i]);
                      break;
                      }
            }
        }
        return ans;
    }
};
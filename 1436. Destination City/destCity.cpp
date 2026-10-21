class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> origin_cities;

        for(auto a:paths)
        {
            origin_cities.insert(a[0]);
        }

        for(auto b:paths){
            if(origin_cities.find(b[1])==origin_cities.end()){
                return b[1];
            }
        }
        return "";
    } 
};
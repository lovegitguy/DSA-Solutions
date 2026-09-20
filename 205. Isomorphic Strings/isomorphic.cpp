class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> st;
        map<char, char> ts;

        for(int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];

            if(st.find(a) != st.end() && st[a] != b) {
                return false;
            }

            if(ts.find(b) != ts.end() && ts[b] != a) {
                return false;
            }

            st[a] = b;
            ts[b] = a;
        }

        return true;
    }
};
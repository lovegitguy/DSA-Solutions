class Solution {
public:
    bool isHappy(int n) {
         set<int> seen;
    while(n!=1){
        if(seen.find(n)!=seen.end()){
            return false;
        }

        seen.insert(n);
        int total=0;

        while(n!=0){
            int digit=n%10;
            total+=digit*digit;
            n=n/10;
        }
        n=total;
    }
    return true;
    }
};
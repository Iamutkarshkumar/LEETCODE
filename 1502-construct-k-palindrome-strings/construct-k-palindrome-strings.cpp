class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> v(26,0);
        if(s.length()<k) return false;
        for(auto ele: s){
            v[ele-'a']++;
        }
        int o=0;
        int e=0;
        for(auto ele: v){
            if(ele==0) continue;
            else{
                if(ele%2==0) e++;
                else o++;
            }
        }
        if(o>k) return false;
        return true;  
    }
};
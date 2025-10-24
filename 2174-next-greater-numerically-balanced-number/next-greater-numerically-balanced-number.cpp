class Solution {
public:
    bool help(int i){
        vector<int> v(10);
        string s=to_string(i);
        for(int idx=0;idx<s.length();idx++){
            if(s[idx]=='0') return false;//0 zero baar aana chahiye 
            v[s[idx]-'0']++;
        }
        for(int j=0;j<10;j++){
            if(v[j]>0 and v[j]!=j) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            if(help(i)) return i;
        }
        return 1;
    }
};
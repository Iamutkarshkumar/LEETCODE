class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> v(n+1,0);
        for(auto ele: shifts){
            int start=ele[0];
            int end=ele[1];
            int x=ele[2];
            v[start]+=(x==0 ? -1 : 1);
            v[end+1]+=(x==0 ? 1 : -1);
        }
        for(int i=1;i<=n;i++) v[i]+=v[i-1];
        for(int i=0;i<n;i++){
            int shift=v[i]%26;
            if(shift<0) shift+=26;
            s[i]='a'+(s[i]-'a'+shift)%26;
        }
        return s;
    }
};
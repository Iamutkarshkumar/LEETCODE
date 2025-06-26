class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int z=0,o=0;
        long long value=0,pow=1;
        for(auto ele: s){
            if(ele=='0') z++;
        } 
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                if(value+pow>k) continue;
                value+=pow;
                o++;
            }
            pow<<=1;
            if(pow>k) break;
        }
        return z+o;
    }
};
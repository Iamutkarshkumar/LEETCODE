class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.length();
        int x=n;
        x-=2;
        while(x--){
            for(int i=0;i<n-1;i++) s[i]=(s[i]+s[i+1])%10;
            s.pop_back();
        }
        return (s[0]==s[1]);
    }
};
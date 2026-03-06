class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0' and s[i+1]=='1') return false;
        }
        return true;
    }
};
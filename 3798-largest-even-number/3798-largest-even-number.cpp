class Solution {
public:
    string largestEven(string s) {
        int n=s.length();
        int i=n-1;
        while(i>=0 and s[i]=='1') i--;
        return s.substr(0,i+1);
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=t.length();
        sort(begin(t),end(t));
        sort(begin(s),end(s));
        for(int i=0;i<n-1;i++){
            if(s[i]!=t[i]) return t[i];
        }
        return t[n-1];
    }
};
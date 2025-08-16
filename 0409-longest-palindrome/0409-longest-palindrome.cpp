class Solution {
public:
    int longestPalindrome(string s){
        vector<int> freq(128,0);
        for(unsigned char c: s) freq[c]++;
        int ans = 0;
        for(int x: freq) ans += (x/2)*2;
        if(ans < (int)s.length()) ans++;
        return ans;
    }
};

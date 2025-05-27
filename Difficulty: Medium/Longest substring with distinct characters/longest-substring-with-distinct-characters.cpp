class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> last(256, -1);
        int mx = 0, l = 0;
        for(int i = 0; i < s.size(); i++){
            l = max(l, last[s[i]] + 1);
            mx = max(mx, i - l + 1);
            last[s[i]] = i;
        }
        return mx;
    }
};

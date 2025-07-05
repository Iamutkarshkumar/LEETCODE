class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> x;
        int i = 0, j = 0;
        while (j < s.length()) {
            if (not x.count(s[j])) {
                x.insert(s[j]);
                ans = max(ans, j - i + 1);   
                j++;
            } 
            else {
                x.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
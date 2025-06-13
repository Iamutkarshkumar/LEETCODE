class Solution {
  void dfs(string &s, int l, vector<string> &res) {
    if (l == s.size() - 1) {
      res.push_back(s);
      return;
    }
    unordered_set<char> used;
    for (int i = l; i < s.size(); i++) {
      if (used.insert(s[i]).second) {
        swap(s[l], s[i]);
        dfs(s, l + 1, res);
        swap(s[l], s[i]);
      }
    }
  }
  
 public:
  vector<string> findPermutation(string &s) {
    vector<string> res;
    sort(s.begin(), s.end());
    dfs(s, 0, res);
    return res;
  }
};
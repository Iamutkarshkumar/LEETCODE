class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        // g[c] will hold a stack of indices of character 'a'+c
        vector<stack<int>> g(26);
        vector<bool> rem(n, false);

        // 1) Mark every ‘*’ for removal, and remove the smallest letter to its left
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                rem[i] = true;           // remove this '*'
                // find the smallest non-star character to its left
                for (int c = 0; c < 26; c++) {
                    if (!g[c].empty()) {
                        rem[g[c].top()] = true;
                        g[c].pop();
                        break;
                    }
                }
            } else {
                // record index of this character
                g[s[i] - 'a'].push(i);
            }
        }

        // 2) Rebuild answer skipping everything marked for removal
        string ans;
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            if (!rem[i]) ans.push_back(s[i]);
        }
        return ans;
    }
};

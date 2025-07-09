
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= a[i]) s.pop();
            ans[i] = s.empty() ? -1 : s.top();
            s.push(a[i]);
        }
        return ans;
    }
};

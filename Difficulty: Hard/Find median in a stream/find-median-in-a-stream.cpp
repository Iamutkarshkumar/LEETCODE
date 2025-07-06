class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        priority_queue<int> low;
        priority_queue<int, vector<int>, greater<int>> high;
        for (int x : arr) {
            if (low.empty() || x <= low.top())
                low.push(x);
            else
                high.push(x);

            if (low.size() > high.size() + 1) {
                high.push(low.top());
                low.pop();
            } else if (high.size() > low.size()) {
                low.push(high.top());
                high.pop();
            }

            if (low.size() == high.size())
                ans.push_back((low.top() + high.top()) / 2.0);
            else
                ans.push_back((double)low.top());
        }
        return ans;
    }
};

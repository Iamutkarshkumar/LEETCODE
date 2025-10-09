#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> done(n + 1, 0); // done[i] = time when wizard i has finished current prefix

        for (int j = 0; j < m; ++j) {
            // forward pass: compute finish times after processing potion j
            for (int i = 0; i < n; ++i) {
                done[i + 1] = max(done[i + 1], done[i]) + (long long)skill[i] * mana[j];
            }
            // backward pass: compute earliest start times for next potion based on immediate-pass constraint
            for (int i = n - 1; i >= 0; --i) {
                done[i] = done[i + 1] - (long long)skill[i] * mana[j];
            }
        }

        return done[n];
    }
};

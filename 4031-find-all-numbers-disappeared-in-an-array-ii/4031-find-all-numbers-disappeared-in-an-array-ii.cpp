class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,int upper) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int cur = lower;

        for (int num : nums) {

            // Ignore numbers outside the required range
            if (num < lower || num > upper) {
                continue;
            }

            // There is a missing interval before num
            if (cur < num) {
                res.push_back({cur, num - 1});
            }

            // num is now covered
            cur = max(cur, num + 1);

            // Everything after upper is irrelevant
            if (cur > upper) {
                break;
            }
        }

        // Handle the remaining numbers after the last element
        if (cur <= upper) {
            res.push_back({cur, upper});
        }

        return res;
    }
};
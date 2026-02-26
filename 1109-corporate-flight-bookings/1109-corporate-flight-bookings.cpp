// class Solution {
// public:
//     vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//         vector<int> ans(n+1,0);
//         for(auto ele: bookings){
//             ans[ele[0]-1]+=ele[2];
//             ans[ele[1]]-=ele[2];
//         }
//         for(int i=1;i<n;i++) ans[i]+=ans[i-1];
//         ans.pop_back();
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);

        for(auto &b : bookings) {
            int start = b[0];
            int end = b[1];
            int count = b[2];

            diff[start] += count;
            diff[end+1] -= count;
        }

        //Cumulative sum
        vector<int> result;
        int cumSum = 0;
        for(int i = 1; i <= n; i++) {
            cumSum += diff[i];
            result.push_back(cumSum);
        }

        return result;
    }
};
// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         int n=nums.size();
//         unordered_set<int> s1,s2;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 s1.insert(nums[i]^nums[j]);
//             }
//         }
//         for(auto ele: s1){
//             for(int k=0;k<n;k++){
//                 s2.insert(nums[k]^ele);
//             }
//         }
//         return s2.size();
//     }
// };
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<bool> s1(2048, false), s2(2048, false);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        for (int x = 0; x < 2048; x++) {
            if (!s1[x]) continue;

            for (int k = 0; k < n; k++) {
                s2[x ^ nums[k]] = true;
            }
        }

        int cnt = 0;
        for (bool x : s2)
            cnt += x;

        return cnt;
    }
};
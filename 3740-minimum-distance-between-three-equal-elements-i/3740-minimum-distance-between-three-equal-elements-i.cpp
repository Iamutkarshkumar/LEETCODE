class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            int x=mp[nums[i]].size();
            if(x>=3){
                auto &v = mp[nums[i]];
                int k=v[x-1];
                ans=min(ans,2*(k-v[x-3]));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
//         unordered_map<int, vector<int>> mp;
//         for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        
//         int ans = INT_MAX;
//         for(auto &ele : mp){
//             auto &v = ele.second;
//             if(v.size() < 3) continue;
//             for(int i=0;i+2<v.size();i++){
//                 int a=v[i], b=v[i+1], c=v[i+2];
//                 int dist = abs(a-b)+abs(b-c)+abs(c-a);
//                 ans = min(ans, dist);
//             }
//         }
//         return ans==INT_MAX ? -1 : ans;
//     }
// };

// class Solution {
// public:
//     static int digitSum(int n){
//         int sum=0;
//         while(n){
//             sum+=(n%10);
//             n/=10;
//         }
//         return sum;
//     }

//     static bool cmp(int &a,int &b){
//         int X=digitSum(a);
//         int Y=digitSum(b);
//         if(X==Y) return a<b;
//         return X<Y;
//     }
//     int minSwaps(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> temp;
//         temp=nums;
//         sort(begin(temp),end(temp),cmp);
//         unordered_map<int,int> mp;
//         for(int i=0;i<n;i++){
//             mp[temp[i]]=i;
//         }

//         vector<bool> vis(n,false);
//         int cycles=0;

//         for(int i=0;i<n;i++){
//             if(vis[i]) continue;

//             int j=i;
//             while(!vis[j]){
//                 vis[j]=true;
//                 j=mp[nums[j]];
//             }
//             cycles++;
//         }

//         return n-cycles;
//     }
// };

// Current complexity:O(nlogn⋅d)
// Suggested complexity:O(NlogN)
// Suggestions:
// Precompute digit sums to avoid redundant calculations during sorting.

class Solution {
public:
    static int digitSum(int n){
        int sum=0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> temp;

        for(int x:nums)
            temp.push_back({digitSum(x),x});

        sort(begin(temp),end(temp));

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[temp[i].second]=i;

        vector<bool> vis(n,false);
        int cycles=0;

        for(int i=0;i<n;i++){
            if(vis[i]) continue;

            int j=i;
            while(!vis[j]){
                vis[j]=true;
                j=mp[nums[j]];
            }
            cycles++;
        }

        return n-cycles;
    }
};
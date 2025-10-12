class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2!=0) ans[i]=ans[i/2]+1;
            else ans[i]=ans[i/2];
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         for(int i=0;i<=n;i++) ans.push_back(__builtin_popcount(i));
//         return ans;
//     }
// };
// class Solution {
// public:
//     int countSetBits(int n){
//         int ans=0;
//         while(n>0){
//             if(n&1==1) ans++;
//             n>>=1;
//         }
//         return ans;
//     }
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         for(int i=0;i<=n;i++){
//             ans.push_back(countSetBits(i));
//         }
//         return ans;
//     }
// };
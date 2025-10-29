class Solution {
public:
    int smallestNumber(int n) {
        int ans=1;
        int x=2;
        while(ans<n){
            ans+=x;
            x*=2;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int smallestNumber(int n) {
//         int count=0;
//         while(n){
//             count++;
//             n>>=1;
//         }
//         int ans=0;
//         while(count--){ 
//             ans<<=1;
//             ans=ans|1;
//         }
//         return ans;
//     }
// };
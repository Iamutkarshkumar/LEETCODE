class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks=n/7;
        int leftDays=n%7;
        int x=28;
        int y=fullWeeks+1;
         long long ans = 0;
        // sum of AP: fullWeeks * (2*a + (fullWeeks-1)*d) / 2
        // a = 28, d = 7
        ans = fullWeeks * (56 + (fullWeeks - 1) * 7LL) / 2LL;
        // while(fullWeeks--){
        //     ans+=x;
        //     x+=7;
        // }
        while(leftDays--){
            ans+=y;
            y++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int totalMoney(int n) {
//         vector<int> v(n);
//         int prev=0,curr=1,count=0;
//         for(int i=0;i<n;i++){
//             if(i%7==0){
//                 count=prev+1;
//                 prev++;
//             }
//             v[i]=count;
//             count++;
//         }
//         int ans=0;
//         for(auto ele: v) ans+=ele;
//         return ans;
//     }
// };

//approach 1
// class Solution {
// public:
//     int minFlips(int a, int b, int c) {
//         int ans=0;
//         while(a or b or c){
//             int x=a&1;
//             int y=b&1;
//             int z=c&1;
//             if(z){
//                 if(x==0 and y==0) ans++;
//             }
//             else{
//                 if(x) ans++;
//                 if(y) ans++;
//             }
//             c>>=1;
//             a>>=1;
//             b>>=1;    
//         } 
//         return ans;
//     }
// };
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a|b)^c) + __builtin_popcount((a&b) & ((a|b)^c));
    }
};
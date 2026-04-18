// class Solution {
// public:
//     int rev(int x){
//         int y=0;
//         while(x>0){
//             y=y*10+x%10;
//             x/=10;
//         }
//         return y;
//     }
//     int mirrorDistance(int n) {
//         return abs(n-rev(n));
//     }
// };
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        
        int rev = stoi(s);
        return abs(n - rev);
    }
};
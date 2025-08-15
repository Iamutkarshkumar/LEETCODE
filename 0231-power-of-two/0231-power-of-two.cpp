// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//       if(n>0 and (n&(n-1))==0) return true;
//       else return false;
//     }
// };
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }
};
// User function Template for C++

class Solution {
  public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n) {
        int x=1;
        while(n>0 or m>0){
            if((n&1)!=(m&1)) return x;
            n>>=1;
            m>>=1;
            x++;
        }
        return -1;
    }
};
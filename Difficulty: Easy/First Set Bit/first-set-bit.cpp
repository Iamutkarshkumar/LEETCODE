// User function Template for C++

class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        int x=1;
        while(n>0){
            if(n&1==1) return x;
            x++;
            n>>=1;
        }
        return x;
    }
};
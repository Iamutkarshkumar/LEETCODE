// User function Template for C++

class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        if(n>0 and (n&(n-1))==0) return true;
        else return false;
    }
};
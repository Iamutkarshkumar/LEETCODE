class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        n>>=k;
        return n&1;
    }
};
// User function Template for C++

class Solution {
  public:
    // Function to check if the number is sparse or not.
    bool isSparse(int n) {
        return (n & (n >> 1)) == 0;
    }
};
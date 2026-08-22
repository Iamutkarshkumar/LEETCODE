class Solution {
    public:
      int minimumStep(int n) {
          int ans = 0;

          // Work backwards from n down to 1
          while (n > 1) {
              if (n % 3 == 0) {
                  n = n / 3;  // Reverse of j = 3 * i
              } else {
                  n = n - 1;  // Reverse of j = i + 1
              }
              ans++;
          }

          return ans;
      }
  };
class Solution {
public:
    // Function to calculate how many numbers exist between prefix and prefix + 1 within the range [1, n]
    int countSteps(int curr, int n) {
        long steps = 0, first = curr, last = curr;
        while (first <= n) {
            steps += min((long)n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // We subtract 1 because we're finding the k-th number (0-indexed)
        
        while (k > 0) {
            int steps = countSteps(curr, n);
            if (steps <= k) {
                // Move to the next number
                k -= steps;
                curr++;
            } else {
                // Go deeper in the current prefix
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};

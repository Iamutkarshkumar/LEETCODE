//Position this line where user code will be pasted.
class Solution {
  public:
    // Helper function to recursively calculate subset sums
    void calculateSubsetSums(vector<int>& arr, int index, int currentSum,
                             vector<int>& result) {
        // Base case: if index exceeds array bounds, store the current sum
        if (index == arr.size()) {
            result.push_back(currentSum);
            return;
        }

        // Include current element in subset and recurse
        calculateSubsetSums(arr, index + 1, currentSum + arr[index], result);

        // Exclude current element from subset and recurse
        calculateSubsetSums(arr, index + 1, currentSum, result);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> subsetSumsResult;
        calculateSubsetSums(arr, 0, 0,
                            subsetSumsResult); // Start from index 0 with sum 0
        return subsetSumsResult;
    }
};
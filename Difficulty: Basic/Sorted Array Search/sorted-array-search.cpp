class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        return binary_search(begin(arr),end(arr),k);
        
    }
};
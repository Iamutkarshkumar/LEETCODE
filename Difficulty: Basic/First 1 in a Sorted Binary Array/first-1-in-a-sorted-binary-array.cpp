class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        int lb= lower_bound(begin(arr),end(arr),1)-begin(arr);
        return (arr[lb]==1 ? lb : -1);
    }
};
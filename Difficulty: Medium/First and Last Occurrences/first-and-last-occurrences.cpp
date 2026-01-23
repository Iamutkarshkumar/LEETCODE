class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int lb=lower_bound(begin(arr),end(arr),x)-begin(arr);
        if(arr[lb]!=x) return {-1,-1};
        int ub=upper_bound(begin(arr),end(arr),x)-begin(arr);
        return {lb,ub-1};
    }
};
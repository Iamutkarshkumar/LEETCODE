class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        int lb=-1,ub=-1;
        lb=lower_bound(begin(arr),end(arr),x)-begin(arr);
        if(arr[lb]!=x) return {-1};
        ub=upper_bound(begin(arr),end(arr),x)-begin(arr);
        return {lb,ub-1};
    }
};
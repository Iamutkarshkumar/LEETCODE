class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count=0;
        int n=arr.size();
        sort(begin(arr),end(arr));
        int l=0,r=n-1;
        while(l<r){
            if(arr[l]+arr[r]<target){
                count+=(r-l);
                l++;
            }
            else r--;
        }
        return count;
    }
};

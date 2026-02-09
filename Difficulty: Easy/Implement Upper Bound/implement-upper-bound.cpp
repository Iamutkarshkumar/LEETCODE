class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=n-1;
        int idx=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(arr[m]>target){
                idx=m;
                r=m-1;
            }
            else l=m+1;
        }
        return idx;
        
    }
};

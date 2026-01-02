class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int l=0,r=n-1;
        
        while(l<r){
            int m=l+(r-l)/2;
            
            if(arr[m]>arr[r]) l=m+1;
            else r=m;
        }
        return l;
    }
};

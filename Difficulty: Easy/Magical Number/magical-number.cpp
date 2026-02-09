class Solution {
  public:
    int findMagicalNumber(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(arr[m]==m){
                ans=m;
                r=m-1;
            }
            else if(arr[m]>m) r=m-1; 
            else l=m+1;
        }
        return ans;
    }
};
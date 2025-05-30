class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n=arr.size();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0]=arr[0];
        suff[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+arr[i];
        for(int i=n-2;i>=0;i--) suff[i]=suff[i+1]+arr[i];
        
        for(int i=0;i<n;i++){
            if(pre[i]==suff[i]) return i;
        }
        return -1;
    }
};
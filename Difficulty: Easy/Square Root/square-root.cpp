class Solution {
  public:
    int floorSqrt(int n) {
        if(n<2) return n;

        long long l=1,r=n/2;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(m*m<=n) l=m+1;
            else r=m-1;
        }
        return r;
    }
};

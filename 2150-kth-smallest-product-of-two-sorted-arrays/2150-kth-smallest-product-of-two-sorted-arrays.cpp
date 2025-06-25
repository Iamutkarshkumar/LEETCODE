class Solution {
public:
    vector<int> nums1,nums2;
    long long countLE(long long x){
        long long cnt=0;
        for(int i=0;i<nums1.size();i++){
            long long a=nums1[i];
            if(a==0){
                if(x>=0) cnt+=nums2.size();
            } 
            else {
                long double t=(long double)x/a;
                if(a>0){
                    long long bound=floor(t);
                    cnt+= upper_bound(nums2.begin(),nums2.end(),bound)
                         - nums2.begin();
                } else {
                    long long bound=ceil(t);
                    cnt+= nums2.end()
                         - lower_bound(nums2.begin(),nums2.end(),bound);
                }
            }
        }
        return cnt;
    }
    long long kthSmallestProduct(vector<int>& A, vector<int>& B, long long k){
        nums1=A; nums2=B;
        long long lo=-100000LL*100000-1,hi=100000LL*100000+1;
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(countLE(mid)>=k) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};

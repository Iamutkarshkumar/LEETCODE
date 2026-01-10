class Solution {
public:
    int m,n,L;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        // numberOfEleInLeftHalf
        L = (m+n+1)/2;

        int l=0,r=m;
        while(l<=r){
            int mid=l+(r-l)/2;
            int x1,x2,x3,x4;
            x1=(mid==0 ? INT_MIN : nums1[mid-1]);
            x2=(mid==m ? INT_MAX : nums1[mid]);
            x3 = (L-mid==0 ? INT_MIN : nums2[L-mid-1]);
            x4 = (L-mid==n ? INT_MAX : nums2[L-mid]);
            if(x1<=x4 && x3<=x2){
                if((m+n)&1) return max(x1,x3);
                return (max(x1,x3)+min(x2,x4))/2.0;
            }
            else if(x1>x4) r=mid-1;
            else l=mid+1;
        }
        return 0.0;
    }
};
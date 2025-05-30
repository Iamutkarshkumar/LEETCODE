class Solution {
public:
    int findPivot(const vector<int>& a){
    int l=0, r=a.size()-1;
    while(l<r){
        int m = l + (r-l)/2;
        if(a[m]>a[r]) l = m+1;
        else           r = m;
    }
    return l;
    }
    int findMin(vector<int>& nums) {
        int l=findPivot(nums);
        return nums[l];
    }
};
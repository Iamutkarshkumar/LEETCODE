class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int x=0;
        if(n%2==0 and m%2==0) return 0;
        else if(n%2==0 and m%2!=0){
            for(auto ele: nums1) x^=ele;
        }
        else if(n%2!=0 and m%2==0){
            for(auto ele: nums2) x^=ele;
        }
        else{
            for(auto ele: nums1) x^=ele;
            for(auto ele: nums2) x^=ele;
        }
        return x;
    }
};
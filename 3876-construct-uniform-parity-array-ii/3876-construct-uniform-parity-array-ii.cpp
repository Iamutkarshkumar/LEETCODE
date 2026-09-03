class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestEven=INT_MAX;
        int smallestOdd=INT_MAX;
        for(auto &ele: nums1){
            if(ele&1) smallestOdd=min(smallestOdd,ele);
            else smallestEven=min(smallestEven,ele);
        }
        if(smallestOdd==INT_MAX) return true;
        if(smallestEven==INT_MAX) return true;
        return smallestOdd<smallestEven;
    }
};
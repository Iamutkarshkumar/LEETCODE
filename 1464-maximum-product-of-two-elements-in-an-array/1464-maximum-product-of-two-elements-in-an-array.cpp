class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN;
        for(int ele: nums){
            if(ele>max1){
                max2=max1;
                max1=ele;
            }
            else if(ele>max2){
                max2=ele;
            }
        }
        return (max1-1)*(max2-1);
    }
};
// method 1: tc O(nlogn)
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         int n=nums.size();
//         sort(begin(nums),end(nums));
//         return max(nums[0]*nums[1]*nums[n-1] , nums[n-3]*nums[n-2]*nums[n-1]);
//     }
// };

//method 2: O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int firstMax=INT_MIN,secondMax=INT_MIN,thirdMax=INT_MIN;
        int firstMin=INT_MAX,secondMin=INT_MAX;
        for(int ele: nums){
            if(ele>firstMax){
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=ele;
            }
            else if(ele>secondMax){
                thirdMax=secondMax;
                secondMax=ele;
            }
            else if(ele>thirdMax){
                thirdMax=ele;
            }

            if(ele<firstMin){
                secondMin=firstMin;
                firstMin=ele;
            }
            else if(ele<secondMin){
                secondMin=ele;
            }
        }
        return max(firstMin*secondMin*firstMax, firstMax*secondMax*thirdMax);
    }
};
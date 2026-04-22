class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto ele: nums){
            while(ele){
                int x=ele%10;
                ele/=10;
                if(x==digit) ans++;
            }
        }
        return ans;
    }
};
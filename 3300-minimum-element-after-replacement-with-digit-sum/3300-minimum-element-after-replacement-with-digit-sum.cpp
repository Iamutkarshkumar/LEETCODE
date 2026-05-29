class Solution {
public:
    int help(int x){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto ele: nums){
            ans=min(ans,help(ele));
        }
        return ans;
    }
};
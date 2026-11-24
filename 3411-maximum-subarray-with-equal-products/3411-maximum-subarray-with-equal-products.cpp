class Solution {
public:
    int gcdOf(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    int lcmOf(int a, int b) {
        return a / gcdOf(a, b) * b;
    }
    int maxLength(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        int maxVal = 0, allLcm = 1;
        for (int x : nums) {
            maxVal = max(maxVal, x);
            allLcm = lcmOf(allLcm, x);
        }
        int limit = allLcm * maxVal;
        for(int i=0;i<n;i++){
            int prod=1,g=0,l=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                g=gcdOf(g,nums[j]);
                l=lcmOf(l,nums[j]);
                if(prod==g*l) ans=max(ans,j-i+1);
                if (prod > limit) break;
            }
        }
        return ans;
    }
};
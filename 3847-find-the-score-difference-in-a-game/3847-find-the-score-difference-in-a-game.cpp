class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1=0,p2=0;
        bool p1Active=true;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((i+1)%6==0) p1Active=!p1Active;
            if((nums[i]&1)==1) p1Active=!p1Active;
            if(p1Active) p1+=nums[i];
            else p2+=nums[i];
        }
        return p1-p2;
    }
};
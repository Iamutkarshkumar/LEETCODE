class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int target=nums[i];
            int x=-1;
            for(int j=1;j<=target;j++){
                if((j | (j+1))==target){
                    x=j;;
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
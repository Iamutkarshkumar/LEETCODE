class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> oddIdx,evenIdx;
        
        for(int i=0;i<n;i++){
            if(nums[i]&1) oddIdx.push_back(i);
            else evenIdx.push_back(i);
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                int idx=upper_bound(begin(evenIdx),end(evenIdx),i)-begin(evenIdx);
                ans.push_back(evenIdx.size()-idx);
            }else{
                int idx=upper_bound(begin(oddIdx),end(oddIdx),i)-begin(oddIdx);
                ans.push_back(oddIdx.size()-idx);
            }
        }
        
        return ans;
    }
};
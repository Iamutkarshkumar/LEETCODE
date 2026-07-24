class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s1,s2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s1.insert(nums[i]^nums[j]);
            }
        }
        for(auto ele: s1){
            for(int k=0;k<n;k++){
                s2.insert(nums[k]^ele);
            }
        }
        return s2.size();
    }
};
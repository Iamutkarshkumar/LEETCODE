class Solution {
public:
    bool help(vector<int> v,int k){
        if(v[1]-v[0]<=k and v[2]-v[1]<=k and v[2]-v[0]<=k) return true;
        else return false;
    }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i+=3){
            v.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        for(auto ele: v){
            if(not help(ele,k)) return {};
        }
        return v;
    }
};
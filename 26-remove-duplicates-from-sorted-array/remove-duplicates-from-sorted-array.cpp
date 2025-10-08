class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(begin(nums),end(nums));
        int i=0;
        for(auto ele: s){
            nums[i++]=ele;
        }
        return s.size();
    }
};
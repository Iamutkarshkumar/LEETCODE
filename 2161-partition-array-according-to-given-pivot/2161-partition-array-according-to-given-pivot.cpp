class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> s;
        for(auto ele: nums){
            if(ele<pivot) s.push_back(ele);
        }
        for(auto ele: nums){
            if(ele==pivot) s.push_back(ele);
        }
        for(auto ele: nums){
            if(ele>pivot) s.push_back(ele);
        }
        return s;
    }
};
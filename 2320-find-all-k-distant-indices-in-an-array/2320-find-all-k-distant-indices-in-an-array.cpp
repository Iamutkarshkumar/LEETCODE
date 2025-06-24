class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v1, v2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) v1.push_back(i);
        }
        for(int i=0;i<nums.size();i++) {
            for(int x:v1){
                if(abs(i-x)<=k){
                    v2.push_back(i);
                    break; 
                }
            }
        }
        return v2;
    }
};
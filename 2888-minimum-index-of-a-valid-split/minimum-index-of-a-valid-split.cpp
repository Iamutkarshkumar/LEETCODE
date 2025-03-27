class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto ele: nums) mp2[ele]++;

        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];

            mp1[x]++;
            mp2[x]--;

            int n1=i+1;
            int n2=n-i-1;

            if(mp1[x]*2>n1 and mp2[x]*2>n2) return i;
        }
        return -1;
    }
};
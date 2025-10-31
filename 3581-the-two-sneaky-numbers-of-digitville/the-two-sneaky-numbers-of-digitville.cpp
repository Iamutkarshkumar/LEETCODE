class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> freq(n,0);
        for(int i: nums) freq[i]++;
        for(int i=0;i<n;i++){
            if(freq[i]==2) ans.push_back(i);
        }
        return ans;
    }
};
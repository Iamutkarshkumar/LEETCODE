class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int x=0;
        for(auto ele: nums){
            ele[x]=='1' ? ans+="0" : ans+="1";
            x++;
        }
        return ans;
    }
};
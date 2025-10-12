class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit=0;bit<=31;bit++){
            int ones=0;
            int temp=(1<<bit);
            for(auto num: nums){
                if(num & temp) ones++;
            }
            if(ones%3) ans =( ans | temp);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(auto ele: nums) mp[ele]++;
//         for(auto ele: mp) if(ele.second==1) return ele.first;
//         return -1; 
//     }
// };
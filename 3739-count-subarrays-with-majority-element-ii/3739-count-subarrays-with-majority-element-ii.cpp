using ll=long long;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<ll,ll> mp;// cumSum->count
        ll cumSum=0;
        mp[0]=1;
        ll validLeftPoints=0;
        ll result=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==target){
                validLeftPoints+=mp[cumSum];
                cumSum+=1;
            }
            else{
                cumSum-=1;
                validLeftPoints-=mp[cumSum];
            }
            mp[cumSum]+=1;
            result+=validLeftPoints;
        }
        return result;
    }
};
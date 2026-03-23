//method 1 
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int,int> mp;
//         mp[0]=1;
//         int n=nums.size();
//         int ans=0;
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             int remaningSum=sum-goal;
//             if(mp.count(remaningSum)) ans+=mp[remaningSum];
//             mp[sum]++;
//         }
//         return ans;
//     }
// };

//method 2
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),i=0,j=0,sum=0,zeroCount=0,ans=0;
        while(j<n){
            sum+=nums[j];
            while(i<j and (nums[i]==0 or sum>goal)){
                if(nums[i]==0) zeroCount++;
                else zeroCount=0;
                sum-=nums[i];
                i++;
            }
            if(sum==goal) ans+=1+zeroCount;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int f(int n) {
        int sum=0;
        while(n) {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int l=nums.size();
        unordered_map<int,int> mp;
        int maxSum=-1;
        for(int num: nums){
            int digitSum = f(num);
            if(mp.find(digitSum) != mp.end()){
                maxSum = max(maxSum, mp[digitSum] + num);
                mp[digitSum] = max(mp[digitSum], num); 
            }
            else mp[digitSum] = num;
        }
        return maxSum;
    }
};
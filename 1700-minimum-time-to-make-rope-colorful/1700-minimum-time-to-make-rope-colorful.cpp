class Solution {
public:
    int sum=0;
    int help(int i,int j,vector<int>& neededTime){
        int x=INT_MIN;
        for(int idx=i;idx<=j;idx++){
            x=max(x,neededTime[idx]);
        }
        return x;
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int i=0;
        while(i<n){
            int j=i;
            while(colors[j]==colors[i]) j++;
            int x=help(i,j-1,neededTime);
            sum+=x;
            i=j;
        }
        int ans=0;
        for(auto ele: neededTime) ans+=ele;
        return ans-sum;
    }
};
// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         unordered_map<char,int> mp;
//         int n=colors.length();
//         for(int i=0;i<n;i++){
//             if(mp.count(colors[i])==0) mp[colors[i]]=neededTime[i];
//             else{
//                 int x=neededTime [i];
//                 int y=mp[colors[i]];
//                 mp[colors[i]]=max(x,y);
//             }
//         }
//         int sum=0;
//         for(auto ele: neededTime) sum+=ele;
//         for(auto ele: mp) sum-=ele.second;
//         return sum;
//     }
// };
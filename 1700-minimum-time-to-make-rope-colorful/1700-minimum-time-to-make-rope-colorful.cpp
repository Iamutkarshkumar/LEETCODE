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

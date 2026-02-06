class Solution {
public:
    bool isPossible(int m,vector<int>& nums, vector<vector<int>>& queries){
        int n=nums.size();
        vector<int> v(n+1,0);
        for(int i=0;i<=m;i++){
            int s=queries[i][0];
            int e=queries[i][1];
            int x=queries[i][2];
            v[s]+=x;
            if(e+1<=n) v[e+1]-=x;
        }
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
            if(nums[i-1]-v[i-1]>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(*max_element(begin(nums),end(nums))==0) return 0;

        int l=0,r=queries.size()-1;
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isPossible(m,nums,queries)){
                ans=m+1;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};
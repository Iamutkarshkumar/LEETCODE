class Solution {
public:
    bool help(vector<int>& v,int req){
        int n=v.size();
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(v[i]==0) count++;
            else break;
        }
        return (count>=req);
    }
    int minSwaps(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j<n and !help(grid[j],n-1-i)) j++;
            if(j==n) return -1;
            while(j>i){
                swap(grid[j],grid[j-1]);
                ans++;
                j--;
            }
            i++;
        }
        return ans;
    }
};
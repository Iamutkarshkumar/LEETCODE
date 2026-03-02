class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> zeros(n);

        // Step 1: Precompute trailing zeros
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) count++;
                else break;
            }
            zeros[i]=count;
        }

        int ans=0;

        // Step 2: Greedy placement
        for(int i=0;i<n;i++){
            int req=n-1-i;
            int j=i;

            while(j<n && zeros[j]<req) j++;
            if(j==n) return -1;

            // Bubble up
            while(j>i){
                swap(zeros[j],zeros[j-1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};
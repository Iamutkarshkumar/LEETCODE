class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=INT_MIN;
        int n=colors.size();
        for(int i=0;i<n-1;i++){
            int eleAtI=colors[i];
            int j=n-1;
            while(j>=0 and colors[j]==eleAtI) j--;
            ans=max(ans,abs(j-i));
        }
        return ans;
    }
};
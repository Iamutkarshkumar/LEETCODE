class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size(),alt=0,ans=0;
        for(int i=0;i<n;i++){
            alt+=gain[i];
            ans=max(ans,alt);
        }
        return ans;
    }
};
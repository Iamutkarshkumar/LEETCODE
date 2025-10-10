class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN;
        int n=energy.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int j=i;
            int sum=0;
            while(j<n){
                visited[j]=1;
                sum+=energy[j];
                sum=max(sum,energy[j]);
                j+=k;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
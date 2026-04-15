class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int d=abs(i-startIndex);
                ans=min({ans,d,n-d});
            }
        }
        return ans==1e9 ? -1 : ans;
    }
};
class Solution {
public:
    int minimumDeletions(string s) {
        int aCount=0,bCount=0;
        int ans=INT_MAX;
        for(auto ele: s) aCount+=(ele=='a');
        for(auto ele: s){
            if(ele=='a') aCount--;
            ans=min(ans,aCount+bCount);
            if(ele=='b') bCount++;
        }
        return ans;
    }
};
class Solution {
public:
    int totalMoney(int n) {
        vector<int> v(n);
        int prev=0,curr=1,count=0;
        for(int i=0;i<n;i++){
            if(i%7==0){
                count=prev+1;
                prev++;
            }
            v[i]=count;
            count++;
        }
        int ans=0;
        for(auto ele: v) ans+=ele;
        return ans;
    }
};
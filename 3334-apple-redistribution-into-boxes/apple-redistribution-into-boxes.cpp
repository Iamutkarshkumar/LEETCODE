class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto ele: apple) sum+=ele;
        sort(begin(capacity),end(capacity),greater<int>());
        int x=0;
        int ans=0;
        for(auto ele: capacity){
            if(x>=sum) break;
            x+=ele;
            ans++;
        }
        return ans;
    }
};
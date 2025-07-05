class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> v(502);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        v[0]=-1;
        int ans=-1;
        for(int i=0;i<v.size();i++)
            if(v[i]==i) ans=i;
        return ans;
    }
};
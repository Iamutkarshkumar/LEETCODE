class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        int minEle=INT_MAX;
        sort(begin(arr),end(arr));
        vector<int> v(n-1);
        for(int i=0;i<n-1;i++){
            v[i]=abs(arr[i]-arr[i+1]);
            minEle=min(minEle,v[i]);
        } 
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(v[i]==minEle) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};
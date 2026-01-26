class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        int minEle=INT_MAX;
        sort(begin(arr),end(arr));
        for(int i=0;i<n-1;i++){
            minEle=min(minEle,abs(arr[i]-arr[i+1]));
        } 
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])==minEle) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<pair<int,int>> st; // {idx,temp}
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() and temp[i]>st.top().second){
                int idx=st.top().first;
                int tem=st.top().second;
                st.pop();
                ans[idx]=i-idx;
            }
            st.push({i,temp[i]});
        }
        return ans;
    }
};
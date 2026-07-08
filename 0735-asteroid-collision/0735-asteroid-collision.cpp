class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ele: asteroids){
            if(ele<0){
                while(!st.empty() and st.top()>0 and st.top()<abs(ele)) st.pop();
                if(!st.empty() and st.top()>0 and st.top()==abs(ele)){
                    st.pop();
                    continue;
                }
                else if(st.empty() or st.top()<0) st.push(ele);
            }
            else st.push(ele);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
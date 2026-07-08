class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &ele: asteroids){
            while(!st.empty() and ele<0 and st.top()>0){
                int sum=ele+st.top();
                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    ele=0;
                    break;
                }
                else{
                    st.pop();
                    ele=0;
                }
            }
            if(ele!=0) st.push(ele);
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
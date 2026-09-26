class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto ele: knowledge) mp.insert({ele[0],ele[1]});

        stack<char> st;
        int i=0;
        int n=s.length();
        while(i<n){
            if(s[i]=='('){
                i++;
                string temp;
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                string key;
                if(mp.count(temp)) key=mp[temp];
                else key="?";
                
                for(auto &ele: key) st.push(ele);
                i++;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
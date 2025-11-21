class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_set<char> unique;
        for(auto ele: s) unique.insert(ele);
        int ans=0;
        for(auto ele: unique){
            int first_idx=-1;
            int last_idx=-1;
            for(int i=0;i<n;i++){
                if(s[i]==ele){
                    if(first_idx==-1) first_idx=i;
                    last_idx=i;
                }
            }
            unordered_set<char> st;
            for(int i=first_idx+1;i<=last_idx-1;i++) st.insert(s[i]);
            ans+=st.size();
        }
        return ans;
    }
};
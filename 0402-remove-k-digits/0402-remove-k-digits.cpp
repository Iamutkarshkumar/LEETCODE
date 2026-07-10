class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string ans;
        for(int i=0;i<n;i++){
            while(ans.size()!=0 and ans.back()>num[i] and k>0){
                ans.pop_back();
                k--;
            } 
            ans.push_back(num[i]);
        }
        while(k > 0 && ans.size()!=0) {
            ans.pop_back();
            k--;
        }
        
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        if(i == ans.size()) return "0";
        return ans.substr(i);
    }
};

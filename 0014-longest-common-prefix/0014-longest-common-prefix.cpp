class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));
        int len=0;
        int n=strs[0].length();
        for(int i=0;i<n;i++){
            char a=strs[0][i];
            int x=0;
            for(auto ele: strs){
                if(ele[i]==a) x++;
            }
            if(x==strs.size()) len++;
            else break;
        }
        return strs[0].substr(0, len);
    }
};
class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int countOne=0;
        int i=0;
        while(i<s.length()){
            if(s[i++]=='1') countOne++;
            if(s[i]=='0'){
                while(s[i]=='0') i++;
                ans+=countOne;
            }   
        }
        return ans;
    }
};
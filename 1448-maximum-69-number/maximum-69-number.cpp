class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int idx=s.length();
        for(int i=s.length();i>=0;i--){
            if(s[i]=='6') idx=i;
        }
        if(idx==s.length()) return num;
        else{
            s[idx]='9';
            return stoi(s);
        }
    }
};
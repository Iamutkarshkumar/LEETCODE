class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();
        string result;
        stack<int> s;
        for(int i=0;i<=n;i++){
            s.push(i+1);
            if(i==n or pattern[i]=='I'){
                while(not s.empty()){
                    result+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return result;
    }
};
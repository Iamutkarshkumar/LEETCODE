class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(26),freq(26);
        for(char ch: s) freq[ch-'a']++;
        string stack;
        for(char ch: s){
            if(!visited[ch-'a']){
                while(!stack.empty() and stack.back()>ch){
                    if(freq[stack.back()-'a']>0){
                        visited[stack.back()-'a']=0;
                        stack.pop_back();
                    }
                    else break;
                } 
                visited[ch-'a']=1;
                stack.push_back(ch);
            }
            freq[ch-'a']--;
        }
        return stack;
    }
};
class Solution {
public:
    bool isVowel(char x){
        x=tolower(x);
        if(x=='a' or x=='e' or x=='i' or 
        x=='o' or x=='u') return true;
        else  return false;
    }
    string reverseVowels(string s) {
        stack<char> help;
        for(auto ele: s){
            if(isVowel(ele)) help.push(ele);
        }
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=help.top();
                help.pop();
            }
        }
        return s;
    }
};
class Solution {
public:
    bool isNumber(char x){
        if(x-'0'>=0 and x-'0'<=9) return true;
        return false;
    }
    bool letter(char x){
        if(x-'a'>=0 and x-'a'<=25) return true;
        return false;
    }
    bool isVowel(char x){
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u') return true;
        return false;
    }
    bool isValid(string word) {
        int v=0,c=0;
        if(word.size()<3) return false;
        for(auto ele: word){
            ele=tolower(ele);
            if(isNumber(ele)) continue;
            else if(letter(ele)){
                if(isVowel(ele)) v++;
                else c++;
            }
            else return false; 
        }
        if(v>0 and c>0) return true;
        else return false;
    }
};
class Solution {
public:
    bool isVowel(char x){
        return (x=='a' or x=='e' or x=='i' or x=='o' or x=='u');
    }
    int maxVowels(string s, int k) {
        int ans=0;
        int i=0,j=0;
        int n=s.length();
        int counter=0;
        while(j<n){
            if(isVowel(s[j])) counter++;
            if(j-i+1==k){
                ans=max(ans,counter);
                counter-=(isVowel(s[i]));
                i++;
            }
            j++;
        }
        return ans;
    }
};
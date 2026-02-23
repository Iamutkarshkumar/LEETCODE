class Solution {
public: 
    int convert(string a){
        int x=0;
        for(char c:a){
            x=x*2+(c-'0');
        }
        return x;
    }
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        unordered_set<int> set;
        for(int i=k-1;i<n;i++){
            set.insert(convert(s.substr(i-k+1,k)));
        }
        string thresh;
        for(int i=0;i<k;i++) thresh.push_back('1');
        int conv=convert(thresh);
        for(int i=0;i<=conv;i++){
            if(set.count(i)==0) return false;
        }
        return true;
    }
};
// User function template for C++
class Solution {
  public:
    bool allZero(vector<int>& freq){
        for(auto ele: freq){
            if(ele!=0) return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
        int n=txt.size();
        vector<int> freq(26,0);
        for(auto ele: pat){
            freq[ele-'a']++;
        }
        
        int i=0,j=0,ans=0;
        int k=pat.size();
        while(j<n){
            freq[txt[j]-'a']--;
            if(j-i+1 == k){
                if(allZero(freq)) ans++;
                freq[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};
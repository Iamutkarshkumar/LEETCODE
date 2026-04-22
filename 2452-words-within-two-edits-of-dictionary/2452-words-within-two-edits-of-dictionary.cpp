class Solution {
public:
    bool isValid(string& a,string& b){
        int count=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) count++;
            if(count>2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size(),m=dictionary.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isValid(queries[i],dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
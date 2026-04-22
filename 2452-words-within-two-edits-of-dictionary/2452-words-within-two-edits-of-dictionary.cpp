class Solution {
public:
    int hamming(string& a,string& b){
        int count=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) count++;
            if(count>2) return count;
        }
        return count;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size(),m=dictionary.size();
        vector<int> hammDist;
        vector<string> ans;
        for(int i=0;i<n;i++){
            int x=INT_MAX;
            for(int j=0;j<m;j++){
                int dist=hamming(queries[i],dictionary[j]);
                x=min(x,dist);
            }
            hammDist.push_back(x);
        }
        for(int i=0;i<n;i++){
            if(hammDist[i]<=2) ans.push_back(queries[i]);
        }
        return ans;
    }
};
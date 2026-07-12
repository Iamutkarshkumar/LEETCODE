class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> rnk;
        vector<int> help=arr;
        sort(begin(help),end(help));
        int r=1;
        for(int i=0;i<n;i++){
            if(!rnk.count(help[i])){
                rnk[help[i]]=r;
                r++;
            }
        }
        for(int i=0;i<n;i++) arr[i]=rnk[arr[i]];
        return arr;
    }
};

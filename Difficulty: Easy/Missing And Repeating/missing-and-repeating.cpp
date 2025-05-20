class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> v(n+1,0);
        int a,b;
        for(auto ele: arr) v[ele]++;
        for(int i=1;i<=n;i++){
            if(v[i]>1) a=i;
            if(v[i]==0) b=i;
        }
        return {a,b};
    }
};
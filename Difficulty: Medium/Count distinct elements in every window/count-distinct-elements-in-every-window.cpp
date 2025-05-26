class Solution {
  public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        vector<int> res;
        int n = arr.size();
    
        for(int i=0; i<k; i++) m[arr[i]]++;
        res.push_back(m.size());
       
        for(int i=k; i<n; i++){
            if(--m[arr[i-k]] == 0) m.erase(arr[i-k]);
            m[arr[i]]++;
            res.push_back(m.size());
        }
        return res;
    }
};
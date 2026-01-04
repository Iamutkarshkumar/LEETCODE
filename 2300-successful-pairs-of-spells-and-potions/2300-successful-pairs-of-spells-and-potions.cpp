class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> ans(n);

        sort(begin(potions),end(potions));
        for(int i=0;i<n;i++){
            double need = ceil((double)success/(double)spells[i]);
            int idx=lower_bound(potions.begin(),potions.end(),need)-potions.begin();
            ans[i]=m-idx;
        }
        return ans;
    }
};
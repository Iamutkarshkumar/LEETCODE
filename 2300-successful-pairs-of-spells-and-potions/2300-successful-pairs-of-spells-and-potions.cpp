using ll=long long;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n=spells.size();
        vector<int> ans(n);
        sort(begin(potions),end(potions));
        
        for(int i=0;i<n;i++){
            ll a=spells[i];
            ll x = (success+a-1)/a; // ceil
            ll idx=lower_bound(begin(potions),end(potions),x)-begin(potions);
            ans[i]=(potions.size()-idx);
        }
        return ans;
    }
};
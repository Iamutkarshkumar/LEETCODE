class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> s(supplies.begin(), supplies.end());
        int n = recipes.size();
        vector<bool> made(n, false);
        bool added = true;
        
        // Process recipes until no new recipe can be made.
        while (added) {
            added = false;
            for (int i = 0; i < n; i++) {
                if (made[i]) continue; // Skip if already made.
                
                bool canMake = true;
                for (const auto &ing : ingredients[i]) {
                    if (s.find(ing) == s.end()) {
                        canMake = false;
                        break;
                    }
                }
                if (canMake) {
                    s.insert(recipes[i]);
                    made[i] = true;
                    added = true;
                }
            }
        }
        
        // Preserve the input order.
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (made[i])
                ans.push_back(recipes[i]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }

    void Union(int x,int y){
        int par_x=find(x);
        int par_y=find(y);

        if(rank[par_x]>rank[par_y]) parent[par_y]=par_x;
        else if(rank[par_x]<rank[par_y]) parent[par_x]=par_y;
        else{
            parent[par_y]=par_x;
            rank[par_x]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for(auto ele: edges){
            if(find(ele[0])!=find(ele[1])) Union(ele[0],ele[1]);
        }
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            int root = find(i);      // fully compress / get true representative
            mp[root]++;
        }

        // 2) Extract component sizes
        vector<long long> sz;
        for (auto &p : mp) 
            sz.push_back(p.second);

        // 3) Compute sum of cross‑product of sizes
        long long sum = 0;
        long long total = accumulate(sz.begin(), sz.end(), 0LL);
        for (long long c : sz) {
            total -= c;
            sum += c * total;
        }

        return sum;
    }
};
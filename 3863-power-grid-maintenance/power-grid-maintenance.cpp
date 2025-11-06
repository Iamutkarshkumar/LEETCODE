class Solution {
public:
    vector<int> parent, rnk;

    int findp(int x){
        return parent[x]==x ? x : parent[x]=findp(parent[x]);
    }
    void unite(int a,int b){
        a=findp(a); b=findp(b);
        if(a==b) return;
        if(rnk[a]>rnk[b]) parent[b]=a;
        else if(rnk[b]>rnk[a]) parent[a]=b;
        else{ parent[b]=a; rnk[a]++; }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // prepare DSU (1..c)
        parent.assign(c+1,0);
        rnk.assign(c+1,0);
        for(int i=1;i<=c;i++) parent[i]=i;

        // union all given connections (guard bounds)
        for(auto &e: connections){
            if(e.size()<2) continue;
            int u=e[0], v=e[1];
            if(u<1||u>c||v<1||v>c) continue;
            unite(u,v);
        }

        // build per-component active sets
        vector< set<int> > comp(c+1);
        vector<char> active(c+1,1); // 1 = active, 0 = erased
        for(int i=1;i<=c;i++){
            int r=findp(i);
            comp[r].insert(i);
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for(auto &q: queries){
            if(q.size()<2) { ans.push_back(-1); continue; }
            int t=q[0], g=q[1];
            if(g<1 || g>c){
                // invalid node id, follow safe behaviour: type2 ignore, type1 -> -1
                if(t==1) ans.push_back(-1);
                continue;
            }
            if(t==1){
                if(active[g]) { ans.push_back(g); continue; }
                int r = findp(g);
                if(comp[r].empty()) ans.push_back(-1);
                else ans.push_back(*comp[r].begin()); // smallest active node in component
            } else if(t==2){
                if(active[g]){
                    active[g]=0;
                    int r = findp(g);
                    auto it = comp[r].find(g);
                    if(it!=comp[r].end()) comp[r].erase(it);
                }
                // no output for type 2
            } else {
                // unknown query type - return -1
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

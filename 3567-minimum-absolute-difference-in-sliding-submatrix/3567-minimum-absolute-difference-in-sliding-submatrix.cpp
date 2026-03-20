class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int M=m-k+1,N=n-k+1;
        vector<vector<int>> ans(M,vector<int>(N,0));
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                vector<int> v;
                
                for(int a=i;a<i+k;a++){
                    for(int b=j;b<j+k;b++){
                        v.push_back(grid[a][b]);
                    }
                }
                
                sort(v.begin(),v.end());
                v.erase(unique(v.begin(),v.end()),v.end());
                
                int l=INT_MAX;
                for(int x=1;x<v.size();x++){
                    l=min(l,abs(v[x]-v[x-1]));
                }
                
                if(l==INT_MAX) l=0;
                ans[i][j]=l;
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
//         int m=grid.size(),n=grid[0].size();
//         int M=m-k+1,N=n-k+1;
//         vector<vector<int>> ans(M,vector<int>(N,0));
//         for(int i=0;i<M;i++){
//             for(int j=0;j<N;j++){
//                 priority_queue<int,vector<int>,greater<int>> pq;
//                 unordered_set<int> s;
//                 for(int a=i;a<i+k;a++){
//                     for(int b=j;b<j+k;b++){
//                         if(!s.count(grid[a][b])){
//                             pq.push(grid[a][b]);
//                             s.insert(grid[a][b]);
//                         }
//                     }
//                 }
//                 int l=INT_MAX;
//                 while(pq.size()>1){
//                     int x=pq.top();pq.pop();
//                     l=min(l,abs(x-pq.top()));
//                 }
//                 if(l==INT_MAX) l=0;
//                 ans[i][j]=l;
//             }
//         }
//         return ans;
//     }
// };
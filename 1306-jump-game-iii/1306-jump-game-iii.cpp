class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();

            if(arr[x]==0) return true;
            int r=x+arr[x];
            int l=x-arr[x];
            if(r>=0 and r<n and visited[r]!=true) {q.push(r);visited[r]=true;}
            if(l>=0 and l<n and visited[l]!=true) {q.push(l);visited[l]=true;}
        }
        return false;
    }
};
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0]=true;
        int steps=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int curr=q.front();q.pop();
                if(curr==n-1) return steps;
                int right=curr+1;
                int left=curr-1;
                if(left>=0 and !visited[left]){
                    q.push(left);
                    visited[left]=true;
                }  
                if(right<=n-1 and !visited[right]){
                    q.push(right);
                    visited[right]=true;
                }
                for(auto ele: mp[nums[curr]]){
                    if(!visited[ele]){
                        q.push(ele);
                        visited[ele]=true;
                    }
                } 
                mp[nums[curr]].clear();
            }
            steps++;
        }
        return steps;
    }
};
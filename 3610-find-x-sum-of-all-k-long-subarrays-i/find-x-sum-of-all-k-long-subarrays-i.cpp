class Solution {
public:
    int xSum(vector<int>& sub,int x){
        unordered_map<int,int> mp;
        for(auto ele: sub) mp[ele]++;

        priority_queue<pair<int,int>> pq;
        for(auto ele: mp) pq.push({ele.second,ele.first});
        if(pq.size()<x){
            int sum=0;
            for(auto ele: sub) sum+=ele;
            return sum;
        }
        int sum=0;
        while(x--){
            auto ele=pq.top();pq.pop();
            sum+=(ele.first*ele.second);
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i+k<=n;i++){
            vector<int> sub(nums.begin()+i,nums.begin()+i+k);
            ans.push_back(xSum(sub,x));
        }
        return ans;
    }
};
// //approach 1 : difference array technique
// class Solution {
// public:
//     int maximumPopulation(vector<vector<int>>& logs){ 
//         int n=logs.size();
//         int base=INT_MAX,last=INT_MIN;
//         for(auto& ele: logs){
//             base=min(base,ele[0]);
//             last=max(last,ele[1]);
//         }
//         int DATsize=last-base+2;
//         vector<int> v(DATsize,0);
//         for(auto ele: logs){
//             v[ele[0]-base]+=1;
//             v[ele[1]-base]-=1;
//         }
//         for(int i=1;i<DATsize;i++) v[i]+=v[i-1];
//         int idxMaxEle=max_element(begin(v),end(v))-begin(v);
//         return base+idxMaxEle;
//     }
// };

//approach 2: Line Sweep
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs){ 
        vector<vector<int>> v;
        for(auto ele: logs){
            v.push_back({ele[0],1});
            v.push_back({ele[1],-1});
        }
        sort(begin(v),end(v));
        int ans=0,sum=0,maxSum=0;
        for(auto ele: v){
            sum+=ele[1];
            if(sum>maxSum){
                maxSum=sum;
                ans=ele[0];
            }
        }
        return ans;
    }
};
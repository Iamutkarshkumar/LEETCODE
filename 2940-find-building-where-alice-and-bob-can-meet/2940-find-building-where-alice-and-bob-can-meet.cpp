// class Solution {
// public:
//     int n;
//     void buildSegTree(int i,int l,int r,vector<int>& ST,vector<int>& arr){
//         if(l==r){
//             ST[i]=l;
//             return;
//         }
//         int mid=l+(r-l)/2;
//         buildSegTree(2*i+1,l,mid,ST,arr);
//         buildSegTree(2*i+2,mid+1,r,ST,arr);
//         int leftMaxIdx=ST[2*i+1];
//         int rightMaxIdx=ST[2*i+2];
//         if(arr[leftMaxIdx]>=arr[rightMaxIdx]) ST[i]=leftMaxIdx;
//         else ST[i]=rightMaxIdx;
//     }
//     int RMIQ(int start,int end,int i,int l,int r,vector<int>& ST,vector<int>& arr){
//         if(r<start or l>end) return -1;
//         if(l>=start and r<=end) return ST[i];

//         int mid=l+(r-l)/2;
//         int leftMaxIdx=RMIQ(start,end,2*i+1,l,mid,ST,arr);
//         int rightMaxIdx=RMIQ(start,end,2*i+2,mid+1,r,ST,arr);
//         if(leftMaxIdx==-1) return rightMaxIdx;
//         if(rightMaxIdx==-1) return leftMaxIdx;
//         if(arr[leftMaxIdx]>=arr[rightMaxIdx]) return leftMaxIdx;
//         return rightMaxIdx;
//     }
//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         n=heights.size();
//         vector<int> segmentTree(4*n);
//         buildSegTree(0,0,n-1,segmentTree,heights);

//         vector<int> ans;
        
//         for(auto ele: queries){
//             int minIdx=INT_MAX;
//             int alice=min(ele[0],ele[1]);
//             int bob=max(ele[0],ele[1]);
//             int low=bob+1;
//             int high=n-1;
//             while(low<=high){
//                 int m=low+(high-low)/2;
//                 int idx=RMIQ(low,m,0,0,n-1,segmentTree,heights);
//                 if(heights[idx]>max(heights[alice],heights[bob])){
//                     minIdx=min(minIdx,idx);
//                     high=m-1;
//                 }
//                 else low=m+1;
//             }
//             ans.push_back(minIdx);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int n;
    void buildSegTree(int i,int l,int r,vector<int>& ST,vector<int>& arr){
        if(l==r){
            ST[i]=l;
            return;
        }
        int mid=l+(r-l)/2;
        buildSegTree(2*i+1,l,mid,ST,arr);
        buildSegTree(2*i+2,mid+1,r,ST,arr);
        int leftMaxIdx=ST[2*i+1];
        int rightMaxIdx=ST[2*i+2];
        if(arr[leftMaxIdx]>=arr[rightMaxIdx]) ST[i]=leftMaxIdx;
        else ST[i]=rightMaxIdx;
    }

    int RMIQ(int start,int end,int i,int l,int r,vector<int>& ST,vector<int>& arr){
        if(r<start or l>end) return -1;
        if(l>=start and r<=end) return ST[i];

        int mid=l+(r-l)/2;
        int leftMaxIdx=RMIQ(start,end,2*i+1,l,mid,ST,arr);
        int rightMaxIdx=RMIQ(start,end,2*i+2,mid+1,r,ST,arr);

        if(leftMaxIdx==-1) return rightMaxIdx;
        if(rightMaxIdx==-1) return leftMaxIdx;
        if(arr[leftMaxIdx]>=arr[rightMaxIdx]) return leftMaxIdx;
        return rightMaxIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n=heights.size();
        vector<int> segmentTree(4*n);
        buildSegTree(0,0,n-1,segmentTree,heights);

        vector<int> ans;

        for(auto ele:queries){
            int alice=min(ele[0],ele[1]);
            int bob=max(ele[0],ele[1]);

            if(alice==bob){
                ans.push_back(alice);
                continue;
            }

            if(heights[bob]>heights[alice]){
                ans.push_back(bob);
                continue;
            }

            int minIdx=INT_MAX;
            int low=bob+1,high=n-1;

            while(low<=high){
                int m=low+(high-low)/2;
                int idx=RMIQ(low,m,0,0,n-1,segmentTree,heights);

                if(idx!=-1 && heights[idx]>max(heights[alice],heights[bob])){
                    minIdx=min(minIdx,idx);
                    high=m-1;
                }
                else low=m+1;
            }

            if(minIdx==INT_MAX) ans.push_back(-1);
            else ans.push_back(minIdx);
        }
        return ans;
    }
};
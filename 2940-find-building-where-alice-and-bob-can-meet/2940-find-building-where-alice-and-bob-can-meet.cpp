// // class Solution {
// // public:
// //     int n;
// //     void buildSegTree(int i,int l,int r,vector<int>& ST,vector<int>& arr){
// //         if(l==r){
// //             ST[i]=l;
// //             return;
// //         }
// //         int mid=l+(r-l)/2;
// //         buildSegTree(2*i+1,l,mid,ST,arr);
// //         buildSegTree(2*i+2,mid+1,r,ST,arr);
// //         int leftMaxIdx=ST[2*i+1];
// //         int rightMaxIdx=ST[2*i+2];
// //         if(arr[leftMaxIdx]>=arr[rightMaxIdx]) ST[i]=leftMaxIdx;
// //         else ST[i]=rightMaxIdx;
// //     }
// //     int RMIQ(int start,int end,int i,int l,int r,vector<int>& ST,vector<int>& arr){
// //         if(r<start or l>end) return -1;
// //         if(l>=start and r<=end) return ST[i];

// //         int mid=l+(r-l)/2;
// //         int leftMaxIdx=RMIQ(start,end,2*i+1,l,mid,ST,arr);
// //         int rightMaxIdx=RMIQ(start,end,2*i+2,mid+1,r,ST,arr);
// //         if(leftMaxIdx==-1) return rightMaxIdx;
// //         if(rightMaxIdx==-1) return leftMaxIdx;
// //         if(arr[leftMaxIdx]>=arr[rightMaxIdx]) return leftMaxIdx;
// //         return rightMaxIdx;
// //     }
// //     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
// //         n=heights.size();
// //         vector<int> segmentTree(4*n);
// //         buildSegTree(0,0,n-1,segmentTree,heights);

// //         vector<int> ans;
        
// //         for(auto ele: queries){
// //             int minIdx=INT_MAX;
// //             int alice=min(ele[0],ele[1]);
// //             int bob=max(ele[0],ele[1]);
// //             int low=bob+1;
// //             int high=n-1;
// //             while(low<=high){
// //                 int m=low+(high-low)/2;
// //                 int idx=RMIQ(low,m,0,0,n-1,segmentTree,heights);
// //                 if(heights[idx]>max(heights[alice],heights[bob])){
// //                     minIdx=min(minIdx,idx);
// //                     high=m-1;
// //                 }
// //                 else low=m+1;
// //             }
// //             ans.push_back(minIdx);
// //         }
// //         return ans;
// //     }
// // };
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

//         for(auto ele:queries){
//             int alice=min(ele[0],ele[1]);
//             int bob=max(ele[0],ele[1]);

//             if(alice==bob){
//                 ans.push_back(alice);
//                 continue;
//             }

//             if(heights[bob]>heights[alice]){
//                 ans.push_back(bob);
//                 continue;
//             }

//             int minIdx=INT_MAX;
//             int low=bob+1,high=n-1;

//             while(low<=high){
//                 int m=low+(high-low)/2;
//                 int idx=RMIQ(low,m,0,0,n-1,segmentTree,heights);

//                 if(idx!=-1 && heights[idx]>max(heights[alice],heights[bob])){
//                     minIdx=min(minIdx,idx);
//                     high=m-1;
//                 }
//                 else low=m+1;
//             }

//             if(minIdx==INT_MAX) ans.push_back(-1);
//             else ans.push_back(minIdx);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    // Builds the segment tree using the max function and stores indices
    void buildSegmentTree(int i, int l, int r, int segmentTree[], vector<int>& heights) {
        if (l == r) {
            segmentTree[i] = l; // Store the index
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);
        
        // Store the index of the maximum element
        segmentTree[i] = (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    // Function to construct the segment tree
    int* constructST(vector<int>& heights, int n) {
        int* segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);
        return segmentTree;
    }

    // Function to query the segment tree for the index of the maximum value in range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[], vector<int>& heights) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }
        
        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, heights);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        // Return the index of the maximum element
        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a to b
    int RMIQ(int st[], vector<int>& heights, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int* segmentTree = constructST(heights, n);

        vector<int> result;
        for(auto& query: queries){
            int alice = min(query[0],query[1]);
            int bob   = max(query[0],query[1]);

            if(alice == bob || heights[bob] > heights[alice]){
                result.push_back(bob);
                continue;
            }

            int l = bob+1;
            int r = n - 1;
            int result_idx = INT_MAX;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segmentTree, heights, n, l, mid);

                if (heights[idx] > max(heights[alice], heights[bob])) {
                    r = mid - 1;
                    result_idx = min(result_idx, idx);
                } else {
                    l = mid + 1;
                }
            }

            if(result_idx == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(result_idx);
            }
        }
        return result;
    }
};
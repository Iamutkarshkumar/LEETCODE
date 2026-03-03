class Solution {
  public:
    void buildSegTree(vector<int>& segTree,int arr[],int i,int l,int r){
        if(l==r){
            segTree[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegTree(segTree,arr,2*i+1,l,mid);
        buildSegTree(segTree,arr,2*i+2,mid+1,r);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    
    int query(vector<int>& segTree,int start,int end,int i,int l,int r){
        if(r<start || l>end) return 0;
        if(l>=start && r<=end) return segTree[i];
        int mid=l+(r-l)/2;
        return query(segTree,start,end,2*i+1,l,mid) 
             + query(segTree,start,end,2*i+2,mid+1,r);
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        vector<int> ans;
        vector<int> segTree(4*n);
        buildSegTree(segTree,arr,0,0,n-1);
        
        int i=0;
        while(q--){
            int x=query(segTree,queries[i]-1,queries[i+1]-1,0,0,n-1);
            ans.push_back(x);
            i+=2;
        }
        return ans;
    }
};
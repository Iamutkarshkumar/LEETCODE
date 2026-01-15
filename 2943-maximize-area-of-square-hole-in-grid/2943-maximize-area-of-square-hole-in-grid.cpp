class Solution {
public:
    int lenOfConsecutive(vector<int>& v){
        if(v.empty()) return 0;
        int ans=1;
        int count=1;
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i+1]-v[i]==1) count++;
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        ans=max(ans,count);
        return ans;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars),end(hBars));
        sort(begin(vBars),end(vBars));
        int h=lenOfConsecutive(hBars);
        int v=lenOfConsecutive(vBars);
        int lenOfSquare=min(h+1,v+1);
        return lenOfSquare*lenOfSquare;
    }
};
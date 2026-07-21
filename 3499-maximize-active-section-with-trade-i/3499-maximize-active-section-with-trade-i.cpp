// class Solution {
// public:
//     int maxActiveSectionsAfterTrade(string s) {
//         int n=s.length();
//         int zeroCount=0;
//         vector<int> zeroIdx;
//         for(int i=0;i<n;i++){
//             if(s[i]=='0'){
//                 zeroCount++;
//                 zeroIdx.push_back(i);
//             }  
//         }
//         for(auto ele: zeroIdx) cout<<ele<<" ";
//         cout<<endl;
//         if(zeroCount==0) return n;
//         if(zeroCount==n) return 0;
//         if(zeroCount==1){
//             int i=zeroIdx[0];
//             return max(i,n-i-1);
//         }

//         int maxDis=INT_MIN; // max distance bw 2 zero 
//         int start=-1,end=-1;
//         for(int i=1;i<zeroIdx.size();i++){
//             int d=zeroIdx[i]-zeroIdx[i-1];
//             if(d>maxDis){
//                 start=zeroIdx[i-1],end=zeroIdx[i];
//                 maxDis=d;
//             }
//         }
//         cout<<start<<" "<<end;
        
//         while(start>0 and s[start]=='0') start--;
//         while(end<n and s[end]=='0') end++;
//         while(start>0 and s[start]=='1') start--;
//         while(end<n and s[end]=='1') end++;
//         return end-start;
//     }
// };

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=0;
        for(char c:s) if(c=='1') ones++;

        string t="1"+s+"1";

        vector<pair<char,int>> runs;

        for(int i=0;i<t.size();){
            int j=i;
            while(j<t.size() && t[j]==t[i]) j++;
            runs.push_back({t[i],j-i});
            i=j;
        }

        int ans=ones;

        for(int i=1;i+1<runs.size();i++){
            if(runs[i].first=='1' &&
               runs[i-1].first=='0' &&
               runs[i+1].first=='0'){
                ans=max(ans,ones+runs[i-1].second+runs[i+1].second);
            }
        }

        return min(ans,n);
    }
};
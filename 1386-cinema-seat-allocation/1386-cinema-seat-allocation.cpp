//TLE
// class Solution {
// public:
//     using ll=long long;
//     ll solve(vector<ll>& row){
//         ll groups=0;
//         bool flag=false;
//         if(row[1]==0 and row[2]==0 and row[3]==0 and row[4]==0){
//             flag=true;
//             groups+=1;
//         }
//         if(row[5]==0 and row[6]==0 and row[7]==0 and row[8]==0){
//             flag=true;
//             groups+=1;
//         }
//         if((row[3]==0 and row[4]==0 and row[5]==0 and row[6]==0) and flag==false){
//             groups+=1;
//         } 
//         return groups;
//     }
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         vector<vector<ll>> seats(n,vector<ll>(10,0));
//         for(auto &ele: reservedSeats){
//             ll r=ele[0]-1;
//             ll c=ele[1]-1;
//             seats[r][c]=1;
//         }
//         ll ans=0;
//         for(auto &row: seats){
//             ll numberOfGroups=solve(row); // we can assign 0 or 1 or 2 grps only
//             ans+=numberOfGroups;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto &ele: reservedSeats) mp[ele[0]].insert(ele[1]);
        int completelyFreeRow = n-mp.size();
        int ans=completelyFreeRow*2;
        for(auto &ele: mp){
            bool grpA=true,grpB=true,grpC=true;
            for(int col=2;col<=9;col++){
                if(col>=2 and col<=5){
                    if(ele.second.count(col)){
                        grpA=false;
                    }
                }
                if(col>=4 and col<=7){
                    if(ele.second.count(col)){
                        grpB=false;
                    }
                }
                if(col>=6 and col<=9){
                    if(ele.second.count(col)){
                        grpC=false;
                    }
                }
            }
            if(grpA&grpC) ans+=2;
            else if(grpA or grpB or grpC) ans+=1;
        }
        return ans;
    }
};

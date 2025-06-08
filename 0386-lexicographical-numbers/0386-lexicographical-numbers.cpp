class Solution {
public:

void solve(int curr,int n,vector<int>&ans){
    if(curr>n)
    return;

    ans.push_back(curr);
    for(int append=0;append<=9;append++){
        int newnum=curr*10+append;
        if(newnum>n)
        return;

        solve(newnum,n,ans);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int startnum=1;startnum<=9;startnum++){
            solve(startnum,n,ans);
        }
        return ans;
    }
};
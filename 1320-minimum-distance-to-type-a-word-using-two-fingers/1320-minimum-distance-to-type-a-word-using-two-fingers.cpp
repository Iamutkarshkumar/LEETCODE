class Solution {
public:
    int dp[305][27][27];
    // Characters are placed like:
    // A B C D E F
    // G H I J K L
    // M N O P Q R
    // S T U V W X
    // Y Z

    // So:
    // row = (c - 'A') / 6
    // col = (c - 'A') % 6
    pair<int,int> getRowCol(int c){
        int row=c/6;
        int col=c%6;
        return {row,col};
    }
    // a → current position of finger (letter index 0–25)
    // b → next letter you want to type
    // 26 → special value → finger not placed yet
    int dist(int a,int b){
        if(a==26 or b==26) return 0;
        auto p1=getRowCol(a),p2=getRowCol(b);
        return abs(p1.first-p2.first)+abs(p1.second-p2.second);
    }
    int f(int i,int f1_pos,int f2_pos,string &word){
        if(i==word.size()) return 0;
        if(dp[i][f1_pos][f2_pos]!=-1) return dp[i][f1_pos][f2_pos];
        int curr=word[i]-'A';
        int use1=dist(f1_pos,curr)+f(i+1,curr,f2_pos,word);
        int use2=dist(f2_pos,curr)+f(i+1,f1_pos,curr,word);
        return dp[i][f1_pos][f2_pos]=min(use1,use2);
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return f(0,26,26,word);
    }
};
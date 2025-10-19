class Solution {
public:
    string rot(string s,int b){
        int n = s.length();
        b %= n;
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        string ans=s;
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string node=q.front();q.pop();
            ans=min(ans,node);

            //rotate
            string rotnode=rot(node,b);
            if(visited.count(rotnode)==0){
                q.push(rotnode);
                visited.insert(rotnode);
            }

            //add at odd indices

            string cyclenode=node;
            for(int i=1;i<node.length();i+=2){
                cyclenode[i] = (((cyclenode[i]-'0')+a)%10)+'0';
            }
            if(visited.count(cyclenode)==0){
                q.push(cyclenode);
                visited.insert(cyclenode);
            }
        }
        return ans;
    }
};
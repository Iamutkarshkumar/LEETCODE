class Solution {
    vector<int> parent, rnk;
    int find(int x){
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    void uni(int a,int b){
        a=find(a);b=find(b);
        if(a==b) return;
        if(rnk[a]>rnk[b]) parent[b]=a;
        else if(rnk[b]>rnk[a]) parent[a]=b;
        else{parent[b]=a;rnk[a]++;}
    }
public:
    string smallestEquivalentString(string s1,string s2,string baseStr){
        parent.resize(26);rnk.assign(26,0);
        for(int i=0;i<26;i++) parent[i]=i;
        for(int i=0;i<s1.size();i++)
            uni(s1[i]-'a',s2[i]-'a');
        vector<int> mn(26);
        for(int i=0;i<26;i++) mn[i]=i;
        for(int i=0;i<26;i++){
            int p=find(i);
            mn[p]=min(mn[p],i);
        }
        for(char &c:baseStr){
            int p=find(c-'a');
            c=char('a'+mn[p]);
        }
        return baseStr;
    }
};

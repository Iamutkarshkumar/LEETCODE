class Solution {
public:
    vector<char> v{'A','C','G','T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        if (!bankset.count(endGene)) return -1; 
        queue<string> que;
        unordered_set<string> visited;
        que.push(startGene);
        visited.insert(startGene);
        int lvl=0;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string x=que.front();que.pop();
                if(x==endGene) return lvl;
                for(auto ele: v){
                    for(int i=0;i<x.length();i++){
                        string nbr =x;
                        nbr[i]=ele;
                        if(bankset.count(nbr) and !visited.count(nbr)) {
                            que.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
class Solution {
public:
    string result="";
    bool solve(int i,string& curr,string& target,vector<int>& freq,bool greater){
        if(i==target.size()){
            if(greater){
                result=curr;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']==0) continue;
            if(greater==false and ch<target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;
            bool isGreater=greater or ch>target[i];
            if(solve(i+1,curr,target,freq,isGreater)) return true;
            //backtrack
            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);
        for(auto ele: s) freq[ele-'a']++;
        string curr;
        solve(0,curr,target,freq,false);
        return result;
    }
};
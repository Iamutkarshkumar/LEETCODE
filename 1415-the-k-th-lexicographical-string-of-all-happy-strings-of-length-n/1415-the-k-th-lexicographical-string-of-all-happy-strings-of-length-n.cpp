class Solution {
public:
    int numberOfHappyStrings(int n){
        return 3*pow(2,n-1);
    }

    void help(string s,char last,int n,vector<string>&res){
        if(s.size()==n){
            res.push_back(s);
            return;
        }

        if(last!='a') help(s+'a','a',n,res);
        if(last!='b') help(s+'b','b',n,res);
        if(last!='c') help(s+'c','c',n,res);
    }

    string getHappyString(int n,int k) {
        int total=numberOfHappyStrings(n);
        if(k>total) return "";

        int each=total/3;

        char start;
        if(k<=each) start='a';
        else if(k<=2*each){
            start='b';
            k-=each;
        }
        else{
            start='c';
            k-=2*each;
        }

        vector<string>res;
        string s="";
        s+=start;

        help(s,start,n,res);

        return res[k-1];
    }
};
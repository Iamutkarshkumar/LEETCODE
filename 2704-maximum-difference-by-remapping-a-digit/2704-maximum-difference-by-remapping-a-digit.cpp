class Solution {
public:
    int minMaxDifference(int num) {
        string maxx=to_string(num);
        string minn=to_string(num);
        char a,b;
        for(int i=0;i<maxx.length();i++){
            if(maxx[i]!='9'){
                a=maxx[i];
                break;
            }
        }
        for(int i=0;i<minn.length();i++){
            if(minn[i]!='0'){
                b=minn[i];
                break;
            }
        }
        replace(maxx.begin(), maxx.end(), a, '9');
        replace(minn.begin(), minn.end(), b, '0');
        return stoi(maxx)-stoi(minn);
    }
};

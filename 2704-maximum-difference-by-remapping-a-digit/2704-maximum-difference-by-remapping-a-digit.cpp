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
        for(int i=0;i<minn.length();i++){
            if(maxx[i]==a){
                maxx[i]='9';
            }
        }
        for(int i=0;i<minn.length();i++){
            if(minn[i]==b){
                minn[i]='0';
            }
        }
        cout<<maxx<<" "<<minn;
        return stoi(maxx)-stoi(minn);
    }
};
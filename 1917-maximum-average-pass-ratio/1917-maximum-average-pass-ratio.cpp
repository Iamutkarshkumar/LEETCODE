using pp = pair<double,pair<int,int>>; 
class Solution{
public:
    double maxAverageRatio(vector<vector<int>>& classes,int extraStudents){
        priority_queue<pp> pq; 
        for(auto &c: classes){
            int x=c[0], y=c[1];
            double gain = (double)(x+1)/(y+1) - (double)x/y;
            pq.push({gain,{x,y}});
        }
        while(extraStudents--){
            auto t=pq.top(); pq.pop();
            int x=t.second.first+1, y=t.second.second+1;
            double gain = (double)(x+1)/(y+1) - (double)x/y;
            pq.push({gain,{x,y}});
        }
        double ans=0;
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            ans += (double)t.second.first / t.second.second;
        }
        return ans / classes.size();
    }
};

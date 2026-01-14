class Solution {
public:
    struct Event{
        long long y,x1,x2;
        int type;
        bool operator<(const Event& other) const {
            return y<other.y;
        }
    };

    vector<long long> xs;
    vector<long long> cnt, seg;

    void pushup(int idx,int l,int r){
        if(cnt[idx]>0) seg[idx]=xs[r]-xs[l];
        else if(l+1==r) seg[idx]=0;
        else seg[idx]=seg[idx*2]+seg[idx*2+1];
    }

    void update(int idx,int l,int r,int ql,int qr,int v){
        if(r<=ql||qr<=l) return;
        if(ql<=l&&r<=qr){
            cnt[idx]+=v;
            pushup(idx,l,r);
            return;
        }
        int m=(l+r)/2;
        update(idx*2,l,m,ql,qr,v);
        update(idx*2+1,m,r,ql,qr,v);
        pushup(idx,l,r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        for(auto &s:squares){
            long long x=s[0],y=s[1],l=s[2];
            events.push_back({y,x,x+l,1});
            events.push_back({y+l,x,x+l,-1});
            xs.push_back(x);
            xs.push_back(x+l);
        }

        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        sort(events.begin(),events.end());

        int n=xs.size();
        cnt.assign(4*n,0);
        seg.assign(4*n,0);

        auto getX=[&](long long x){
            return lower_bound(xs.begin(),xs.end(),x)-xs.begin();
        };

        double total=0;
        long long prevY=events[0].y;

        for(auto &e:events){
            double dy=e.y-prevY;
            total+=seg[1]*dy;
            update(1,0,n,getX(e.x1),getX(e.x2),e.type);
            prevY=e.y;
        }

        double half=total/2.0;
        cnt.assign(4*n,0);
        seg.assign(4*n,0);

        prevY=events[0].y;
        double cur=0;

        for(auto &e:events){
            double dy=e.y-prevY;
            if(cur+seg[1]*dy>=half){
                return prevY+(half-cur)/seg[1];
            }
            cur+=seg[1]*dy;
            update(1,0,n,getX(e.x1),getX(e.x2),e.type);
            prevY=e.y;
        }
        return prevY;
    }
};

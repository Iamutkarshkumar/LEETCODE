class Solution {
public:
    int perm(string &tiles,int i){
        int count=1;
        unordered_set<char> s;
        for(int idx=i;idx<tiles.size();idx++){
            if(s.count(tiles[idx])) continue;
            s.insert(tiles[idx]);
            swap(tiles[idx],tiles[i]);
            count += perm(tiles,i+1);
            swap(tiles[idx],tiles[i]);
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        return perm(tiles,0)-1;
    }
};
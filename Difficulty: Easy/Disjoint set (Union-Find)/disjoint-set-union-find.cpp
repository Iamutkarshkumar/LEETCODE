/*Complete the functions below*/
int find(int par[], int x) {
    if(x==par[x]) return x;
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    int p_x=find(par,x);
    int p_z=find(par,z);
    if(p_x!=p_z) par[p_x]=p_z;
}
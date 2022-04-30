vector<int> bit[N], node[N];
void fakeUpd(int i, int j){
    for(;i <= n;i += i&-i)
        node[i].pb(j);
}
void fakeGet(int i, int j){
    for(;i > 0;i ^= i&-i)
        node[i].pb(j);
}
void upd(int x, int y, int val){
    for(int i = x;i <= n;i += i&-i){
        int j = lower_bound(all(node[i]), y) - node[i].begin() + 1;
        for(;j <= SZ(node[i]);j += j&-j)
            maxx(bit[i][j-1], val);
    }
}
int get(int x, int y){
    int res = 0;
    for(int i = x;i > 0;i ^= i&-i){
        int j = lower_bound(all(node[i]), y) - node[i].begin() + 1;
        for(;j > 0;j ^= j&-j)
            maxx(res, bit[i][j-1]);
    }
    return res;
}

int cha[100005], sz[100005], n;
int root(int u){return u == cha[u] ? u : cha[u] = root(cha[u]);}
bool join(int u,int v){
    u = root(u); v = root(v);
    if(u == v)return 0;
    if(sz[u] < sz[v])swap(u, v);
    sz[u] += sz[v];
    cha[v] = u;
    return 1;
}
void init(){
    for(int i = 1;i <= n;++i){
        cha[i] = i;
        sz[i] = 1;
    }
}

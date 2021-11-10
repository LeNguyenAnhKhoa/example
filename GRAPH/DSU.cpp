const int N = 1e5 + 5;
int p[N], sz[N], n;
int root(int u){
    return u == p[u] ? u : p[u] = root(p[u]);
}
bool join(int u,int v){
    u = root(u), v = root(v);
    if(u == v)return 0;
    if(sz[u] < sz[v])swap(u, v);
    sz[u] += sz[v];
    p[v] = u;
    return 1;
}
void init(){
    for(int i = 1;i <= n;++i)
        cha[i] = i, sz[i] = 1;
}

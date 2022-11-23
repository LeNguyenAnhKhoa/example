void DFS(int u){
    in[u] = ++t;
    FOR(i, 1, l)p[i][u] = p[i-1][p[i-1][u]];
    for(auto v : a[u])if(v != p[0][u])
        p[0][v] = u, DFS(v);
    out[u] = t;
}
void init(){
    l = log2(n);
    DFS(1);
    in[0] = -1e9;
    out[0] = 1e9;
}
bool ck(int u, int v){
    return in[u] <= in[v] && out[v] <= out[u];
}
int lca(int u, int v){
    if(ck(u, v))return u; if(ck(v, u))return v;
    FOD(i, l, 0)if(!ck(p[i][u], v))u = p[i][u];
    return p[0][u];
}

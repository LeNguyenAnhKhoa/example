const int N = 1e5 + 5;
int n, p[17][N], d[N];
vector<int> a[N];
void dfs(int u){
    FOR(i, 1, log2(n))
        p[i][u] = p[i-1][p[i-1][u]];
    for(auto v : a[u])if(v != p[0][u])
        d[v] = d[u] + 1, p[0][v] = u, dfs(v);
}
int lca(int u, int v){
    if(d[u] < d[v])swap(u, v);
    int diff = d[u] - d[v];
    FOD(i, log2(n), 0)
        if(diff>>i&1)u = p[i][u];
    if(u == v)return u;
    FOD(i, log2(n), 0)if(p[i][u] != p[i][v])
        u = p[i][u], v = p[i][v];
    return p[0][u];
}

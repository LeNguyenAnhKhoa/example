const int N = 1e5 + 5;
int n, p[17][N], d[N];
vector<int> a[N];
void DFS(int u){
    for(int i = 1;1<<i <= n;++i)
        p[i][u] = p[i-1][p[i-1][u]];
    for(auto v : a[u])if(v != p[0][u])
        d[v] = d[u] + 1, DFS(v);
}
int lca(int u,int v){
    if(d[u] < d[v])swap(u, v);
    int diff = d[u] - d[v];
    for(int i = log2(n);i >= 0;--i)
        if(diff>>i&1)u = p[i][u];
    if(u == v)return u;
    for(int i = log2(n);i >= 0;--i)if(p[i][u] != p[i][v])
        u = p[i][u], v = p[i][v];
    return p[0][u];
}

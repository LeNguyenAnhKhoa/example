const int N = 1e5 + 5;
int n, jump[17][N], d[N];
vector<int> a[N];

void DFS(int u){
    for(int i = 1;1<<i <= n;++i)
        jump[i][u] = jump[i-1][jump[i-1][u]];
    for(auto v : a[u])if(v != jump[0][u])
        d[v] = d[u] + 1, DFS(v);
}

int lca(int u,int v){
    if(d[u] < d[v])swap(u, v);
    int diff = d[u] - d[v];
    for(int i = log2(n);i >= 0;--i)
        if(diff>>i&1)u = jump[i][u];
    if(u == v)return u;
    for(int i = log2(n);i >= 0;--i)if(jump[i][u] != jump[i][v])
        u = jump[i][u], v = jump[i][v];
    return jump[0][u];
}

const int N = 2e5 + 5;
int n, sz[N], vis[N], pa[N];
vector<int> a[N];

int dfs(int u, int p = 0){
    sz[u] = 1;
    for(auto v : a[u])if(!vis[v] && v != p)
        sz[u] += dfs(v, u);
    return sz[u];
}

int centroid(int m, int u, int p = 0){
    for(auto v : a[u])if(!vis[v] && v != p && sz[v] >= m)
        return centroid(m, v, u);
    return u;
}

void build(int u = 1, int p = 0){
    int c = centroid(dfs(u)>>1, u);
    vis[c] = 1, pa[c] = p;
    for(auto v : a[c])
        if(!vis[v])build(v, c);
}

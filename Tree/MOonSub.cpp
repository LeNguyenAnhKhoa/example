const int N = 1e5 + 5;
const int bl = sqrt(N);
struct qr{
    int l, r, lca, i;
    bool operator <(const qr &a) const{
        return l/bl == a.l/bl ? r < a.r : l < a.l;
    }
}f[N];

int n, q, c[N], jump[17][N], d[N], vis[N], st[N], en[N], j, a[N*2], mp[N];
vector<int> adj[N];
void DFS(int u){
    st[u] = ++j;
    a[j] = u;
    for(int i = 1;1<<i <= n;++i)
        jump[i][u] = jump[i-1][jump[i-1][u]];
    for(auto v : adj[u])if(v != jump[0][u])
        jump[0][v] = u, d[v] = d[u] + 1, DFS(v);
    en[u] = ++j;
    a[j] = u;
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

void add(int x){
    if(vis[x]){
        if(--mp[c[x]] == 0)j--;
    }
    else{
        if(mp[c[x]]++ == 0)j++;
    }
    vis[x] ^= 1;
}

///u -> v:
///nếu v đc thăm trc u swap(u, v) -> ưu tiên u
///nếu lca = u truy vấn đoạn [st[u]..st[v]]
///nếu không: truy vấn đoạn [en[u]..st[v]] + lca
void xuly(){
    for(int i = 1;i <= q;++i){
        int u, v; scanf("%d%d", &u, &v);
        if(st[u] > st[v])swap(u, v);
        int k = lca(u,v);
        if(k == u)f[i] = {st[u], st[v], 0, i};
        else f[i] = {en[u], st[v], k, i};
    }
    sort(f + 1, f + 1 + q);
    int l = 1, r = 0;
    for(int i = 1;i <= q;++i){
        while(r < f[i].r)add(a[++r]);
        while(r > f[i].r)add(a[r--]);
        while(l > f[i].l)add(a[--l]);
        while(l < f[i].l)add(a[l++]);
        if(f[i].lca != 0)add(f[i].lca);
        d[f[i].i] = j;
        if(f[i].lca != 0)add(f[i].lca);
    }
}

const int N = 2e5 + 5;
int n, sz[N], d[N], p[N], head[N], pos[N], cnt;
vector<int> a[N];

void DFS(int u){
    sz[u] = 1;
    for(int v : a[u])if(v != p[u]){
        d[v] = d[u] + 1;
        p[v] = u;
        DFS(v);
        sz[u] += sz[v];
    }
}

void hld(int u,int top)
{
    pos[u] = ++cnt;
    head[u] = top;
    int best = - 1;
    for(int v : a[u])if(v != cha[u])
        if(best == -1 or sz[v] > sz[best])best = v;
    if(best == -1)return;
    hld(best,top);
    for(int v : a[u])if(v != cha[u] && v != best)hld(v,v);
}

int lca(int u,int v){
    while(head[u] != head[v]){
        if(d[head[u]] < d[head[v]])swap(u,v);
        u = cha[head[u]];
    }
    return d[u] < d[v] ? u : v;
}

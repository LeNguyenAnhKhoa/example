int n, sz[200005], d[200005], cha[200005];
int head[200005], pos[200005], cnt;
vector<int> a[200005];

void DFS(int u){
    sz[u] = 1;
    for(int v : a[u])if(v != cha[u]){
        d[v] = d[u] + 1;
        cha[v] = u;
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

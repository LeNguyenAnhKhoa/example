struct edge{
    int u, v, cap, flow;
};
int n, s, t, m, cur[N], d[N], sz[N], ne;
vector<int> a[N];
vector<edge> e;
void add(int u,int v,int cap){
    edge e1 = {u, v, cap, 0};
    edge e2 = {v, u, 0, 0};
    a[u].pb(ne); e.pb(e1);
    a[v].pb(ne+1); e.pb(e2);
    ne += 2;
}
bool bfs(){
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(s); d[s] = 0;
    while(!q.empty() && d[t] < 0){
        int u = q.front(); q.pop();
        for(auto i : a[u]){
            int v = e[i].v;
            if(d[v] < 0 && e[i].flow < e[i].cap)
                q.push(v), d[v] = d[u] + 1;
        }
    }
    return d[t] >= 0;
}
int dfs(int u,int val){
    if(!val)return 0;
    if(u == t)return val;
    for(; cur[u] < sz[u]; ++cur[u]){
        int i = a[u][cur[u]], v = e[i].v;
        if(d[v] != d[u] + 1)continue;
        int pushed = dfs(v, min(val, e[i].cap - e[i].flow));
        if(pushed){
            e[i].flow += pushed;
            e[i^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
int maxflow(){
    int res = 0;
    while(bfs()){
        memset(cur, 0, sizeof cur);
        while(1){
            int val = dfs(s, 1e9);
            if(!val)break;
            res += val;
        }
    }
    return res;
}
void init(){
    s = 1, t = n;
    FOR(i, 1, n)sz[i] = SZ(a[i]);
}

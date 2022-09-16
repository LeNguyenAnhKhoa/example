struct edge{
    int v, cap, flow;
};
vector<edge> e;
vector<int> a[N];
int n, m, s, t, ne, d[N], cnt, vis[N];
void add(int u, int v, int cap){
    e.pb({v, cap, 0});
    e.pb({u, 0, 0});
    a[u].pb(ne);
    a[v].pb(ne+1);
    ne += 2;
}
bool bfs(){
    queue<int> q;
    q.push(s);
    memset(d, 0, sizeof d);
    d[s] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == t)return 1;
        for(auto id : a[u]){
            if(d[e[id].v])continue;
            if(e[id].cap - e[id].flow > 0){
                d[e[id].v] = d[u] + 1;
                q.push(e[id].v);
            }
        }
    }
    return 0;
}
int dfs(int u, int pushed){
    if(u == t)return pushed;
    if(vis[u] == cnt)return 0;
    vis[u] = cnt;
    int res = 0;
    for(auto id : a[u]){
        if(d[e[id].v] != d[u] + 1)continue;
        if(vis[e[id].v] == cnt)continue;
        if(e[id].flow < e[id].cap){
            int f = dfs(e[id].v, min(pushed, e[id].cap - e[id].flow));
            res += f;
            pushed -= f;
            e[id].flow += f;
            e[id^1].flow -= f;
        }
    }
    return res;
}
int maxflow(){
    int res = 0;
    while(1){
        if(!bfs())break;
        cnt++;
        int f = dfs(s, 1e18);
        if(!f)break;
        res += f;
    }
    return res;
}

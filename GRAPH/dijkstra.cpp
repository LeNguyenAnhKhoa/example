int d[100005], n;
vector<ii> a[100005];
int dijkstra(int s,int t){
    memset(d, 0x7f, sizeof d);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s}); d[s] = 0;
    while(!q.empty()){
        int u = q.top().se, du = q.top().fi; q.pop();
        if(du != d[u])continue;
        for(auto v : a[u])if(d[v.se] > du + v.fi){
            d[v.se] = du + v.fi;
            q.push({d[v.se], v.se});
        }
    }
    return d[t];
}

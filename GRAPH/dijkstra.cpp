#define fi first
#define se second
typedef pair<int,int> ii;
const int N = 1e5 + 5;
int n;
vector<ii> a[N];
vector<int> dijkstra(int s){
    vector<int> d(n+5, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s}), d[s] = 0;
    while(!q.empty()){
        int u = q.top().se, du = q.top().fi; q.pop();
        if(du != d[u])continue;
        for(auto v : a[u])if(d[v.se] > du + v.fi)
            d[v.se] = du + v.fi, q.push({d[v.se], v.se});
    }
    return d
}

/// https://codeforces.com/blog/entry/43230
int n, m, c[N], in[N], out[N], t, p[16][N], ans[N], l, dd[N], pos[2*N];
vector<int> a[N];
multiset<int> ss, s;
void DFS(int u){
    in[u] = ++t;
    pos[t] = u;
    FOR(i, 1, l)p[i][u] = p[i-1][p[i-1][u]];
    for(auto v : a[u])if(v != p[0][u])
        p[0][v] = u, DFS(v);
    out[u] = ++t;
    pos[t] = u;
}
void init(){
    l = log2(n);
    DFS(1);
    in[0] = -1e9;
    out[0] = 1e9;
}
bool ck(int u, int v){
    return in[u] <= in[v] && out[v] <= out[u];
}
int lca(int u, int v){
    if(ck(u, v))return u; if(ck(v, u))return v;
    FOD(i, l, 0)if(!ck(p[i][u], v))u = p[i][u];
    return p[0][u];
}
typedef long long ll;
const int S = log2(2*N)+1;
ll gilbertOrder(int x, int y){
    ll d = 0;
    for (int s = 1 << (S - 1); s; s >>= 1){
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry){
            if (rx){
                x = (1 << S) - x;
                y = (1 << S) - y;
            }
            swap(x, y);
        }
    }
    return d;
}
struct node{
    int l, r, e, i;
    ll ord;
    bool operator <(const node &a) const{
        return ord < a.ord;
    }
}q[N];
void add(int i){
    if(!dd[i]){
        auto it = s.insert(c[i]);
        if(it == s.begin() && next(it) != s.end())
            ss.insert(*next(it) - c[i]);
        else if(next(it) == s.end() && it != s.begin())
            ss.insert(c[i] - *prev(it));
        else if(next(it) != s.end() && it != s.begin()){
            ss.erase(ss.find(*next(it) - *prev(it)));
            ss.insert(*next(it) - c[i]);
            ss.insert(c[i] - *prev(it));
        }
    }
    else{
        auto it = s.find(c[i]);
        if(it == s.begin() && next(it) != s.end())
            ss.erase(ss.find(*next(it) - c[i]));
        else if(next(it) == s.end() && it != s.begin())
            ss.erase(ss.find(c[i] - *prev(it)));
        else if(next(it) != s.end() && it != s.begin()){
            ss.erase(ss.find(*next(it) - c[i]));
            ss.erase(ss.find(c[i] - *prev(it)));
            ss.insert(*next(it) - *prev(it));
        }
        s.erase(it);
    }
    dd[i] ^= 1;
}
void solve(){
    sort(q + 1, q + 1 + m);
    int l = 1, r = 0;
    FOR(i, 1, m){
        while(l < q[i].l)add(pos[l++]);
        while(l > q[i].l)add(pos[--l]);
        while(r < q[i].r)add(pos[++r]);
        while(r > q[i].r)add(pos[r--]);
        ans[q[i].i] = *ss.begin();
        if(q[i].e){
            auto it = s.insert(q[i].e);
            if(it != s.begin())
                minn(ans[q[i].i], q[i].e - *prev(it));
            if(next(it) != s.end())
                minn(ans[q[i].i], *next(it) - q[i].e);
            s.erase(it);
        }
    }
    FOR(i, 1, m)cout << ans[i] << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
//         freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    FOR(i, 1, n)cin >> c[i];
    FOR(i, 2, n){
        int u, v; cin >> u >> v;
        a[u].pb(v), a[v].pb(u);
    }
    init();
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        if(in[u] > in[v])swap(u, v);
        int k = lca(u, v);
        if(u == k)q[i] = {in[u], in[v], 0, i, gilbertOrder(in[u], in[v])};
        else q[i] = {out[u], in[v], c[k], i, gilbertOrder(out[u], in[v])};
    }
    solve();
}

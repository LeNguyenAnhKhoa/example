int p[N], sz[N];
vector<ii> Sz, P;
int root(int u){
    return u == p[u] ? u : root(p[u]);
}
void join(int u, int v){
    u = root(u), v = root(v);
    if(sz[u] < sz[v])swap(u, v);
    P.pb({v, p[v]});
    Sz.pb({u, sz[u]});
    if(u != v){
        p[v] = u;
        sz[u] += sz[v];
    }
}
void rollback(){
    p[P.back().fi] = P.back().se;
    P.pop_back();
    sz[Sz.back().fi] = Sz.back().se;
    Sz.pop_back();
}

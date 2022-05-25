const int N = 1e5 + 5;
struct dsu{
    int p[N];
    void init(){
        FOR(i, 1, n)
            p[i] = -1;
    }
    int root(int u){
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
    bool join(){
        if((u = root(u)) == (v = root(v)))return 0;
        if(p[u] > p[v])swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

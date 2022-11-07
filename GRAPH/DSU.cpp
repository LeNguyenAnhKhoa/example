const int N = 1e5 + 5;
int p[N];
int root(int u){
    return p[u] < 0 ? u : p[u] = root(p[u]);
}
bool join(int u, int v){
    if((u = root(u)) == (v = root(v)))return 0;
    if(p[u] > p[v])swap(u, v);
    p[u] += p[v], p[v] = u;
    return 1;
}

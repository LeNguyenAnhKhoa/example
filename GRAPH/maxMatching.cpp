vector<int> g[N];
int mt[N];
bool used[N], used1[N];
bool try_kuhn(int v) {
    if (used[v])return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
int maxMatching(){
    memset(mt, -1, sizeof mt);
    memset(used1, 0, sizeof used1);
    FOR(v, 1, n)for(auto to : g[v])if(mt[to] == -1){
        mt[to] = v;
        used1[v] = 1;
        break;
    }
    FOR(v, 1, n)if(!used1[v]){
        memset(used, 0, sizeof used);
        try_kuhn(v);
    }
    int res = 0;
    FOR(v, 1, n)if(mt[v] != -1){
        ++res;
//        cout << v << ' ' << mt[v] << endl;
    }
    return res;
}

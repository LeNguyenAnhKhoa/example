void cal(int s){
    memset(d, 0x3f, sizeof d);
    FOR(i, 1, n)f[i] = 2;
    d[s] = 0;
    deque<int> q;
    q.pb(s);
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        f[u] = 0;
        for(auto x : a[u]){
            int v = x.fi, w = x.se;
            if(minn(d[v], d[u] + w)){
                if(f[v] == 2){
                    f[v] = 1;
                    q.pb(v);
                }
                else if(!f[v]){
                    f[v] = 1;
                    q.push_front(v);
                }
            }
        }
    }
}

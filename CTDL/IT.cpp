struct IT{
    int st[4*N];
    void build(int id = 1, int l = 1, int r = n){
        if(l == r){
            st[id] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(id<<1, l, mid);
        build(id<<1|1, mid+1, r);
        st[id] = min(st[id<<1], st[id<<1|1]);
    }
    void add(int i, int val, int id = 1, int l = 1, int r = n){
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = l + r >> 1;
        if(i <= mid)add(i, val, id<<1, l, mid);
        else add(i, val, id<<1|1, mid+1, r);
        st[id] = min(st[id<<1], st[id<<1|1]);
    }
    int get(int u, int v, int id = 1, int l = 1, int r = n){
        if(l > v or r < u)return 1e9;
        if(u <= l && r <= v)return st[id];
        int mid = l + r >> 1;
        return min(get(u, v, id<<1, l, mid), get(u, v, id<<1|1, mid+1, r));
    }
};

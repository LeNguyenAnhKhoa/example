struct Lazy_Seg{
    int st[400005], lz[400005];
    void build(int a[], int id = 1,int l = 1,int r = n){
        if(l == r){
            st[id] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, id<<1, l, mid);
        build(a, id<<1|1, mid+1, r);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    void push(int id,int l,int r){
        if(lz[id] == 0)return;
        int mid = l + r >> 1;
        st[id<<1] += lz[id];
        st[id<<1|1] += lz[id];
        lz[id<<1] += lz[id];
        lz[id<<1|1] += lz[id];
        lz[id] = 0;
    }
    void update(int u,int v,int val, int id = 1,int l = 1,int r = n){
        if(l > v || r < u)return;
        if(u <= l && r <= v){
            st[id] += val;
            lz[id] += val;
            return;
        }
        push(id, l, r);
        int mid = l + r >> 1;
        update(u, v, val, id<<1, l, mid);
        update(u, v, val, id<<1|1, mid+1, r);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    int get(int u,int v,int id = 1,int l = 1,int r = n){
        if(l > v or r < u)return 0;
        if(u <= l && r <= v)return st[id];
        push(id, l, r);
        int mid = l + r >> 1;
        return get(u, v, id<<1, l, mid) + query(u, v, id<<1|1, mid+1, r);
    }
};

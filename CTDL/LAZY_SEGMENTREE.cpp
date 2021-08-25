struct Lazy_Seg{
    int st[400005], lz[400005];
    void build(int id,int l,int r,int a[]){
        if(l == r){
            st[id] = a[l];
            return;
        }
        build(id<<1, l, mid, a);
        build(id<<1|1, mid+1, r, a);
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
    void update(int id,int l,int r,int u,int v,int val){
        if(l > v || r < u)return;
        if(u <= l && r <= v){
            st[id] += val;
            lz[id] += val;
            return;
        }
        push(id, l, r);
        int mid = l + r >> 1;
        update(id<<1, l, mid, u, v, val);
        update(id<<1|1, mid+1, r, u, v, val);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    int query(int id,int l,int r,int u,int v){
        if(l > v or r < u)return 0;
        if(u <= l && r <= v)return st[id];
        push(id, l, r);
        int mid = l + r >> 1;
        return query(id<<1, l, mid, u, v) + query(id<<1|1, mid+1, r, u, v);
    }
};

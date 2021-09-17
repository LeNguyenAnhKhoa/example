struct IT{
    int st[400005];
    void update(int i,int val,int id = 1,int l = 1,int r = n){
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = l + r >> 1;
        if(i <= mid)update(i, val, id<<1, l, mid);
        else update(i, val, id<<1|1, mid+1, r);
        st[id] = max(st[id<<1], st[id<<1|1]);
    }
    int get(int u,int v,int id = 1,int l = 1,int r = n){
        if(l > v or r < u)return 0;
        if(u <= l && r <= v)return st[id];
        int mid = l + r >> 1;
        return max(get(u, v, id<<1, l, mid), get(u, v, id<<1|1, mid+1, r));
    }
};

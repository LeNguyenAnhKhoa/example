struct IT{
    int st[400005];
    void update(int i,int val,int id = 1,int l = 1,int r = n){
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = l + r >> 1;
        if(i <= mid)update(id<<1, l, mid, i, val);
        else update(id<<1|1, mid+1, r, i, val);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    int get(int u,int v, int id,int l,int r){
        if(l > v or r < u)return 0;
        if(u <= l && r <= v)return st[id];
        int mid = l + r >> 1;
        return max((id<<1, l, mid, u, v), get(id<<1|1, mid+1, r, u, v));
    }
};

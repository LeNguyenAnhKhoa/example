const int N = 1e5 + 5;
int n;
struct Lazy_Seg{
    int st[4*N], lz[4*N];
    void build(int a[], int id = 1, int l = 1, int r = n){
        if(l == r){
            st[id] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, id<<1, l, mid);
        build(a, id<<1|1, mid+1, r);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    void push(int id, int l, int r){
        if(lz[id] == 0)return;
        int mid = l + r >> 1;
        st[id<<1] += lz[id];
        st[id<<1|1] += lz[id];
        lz[id<<1] += lz[id];
        lz[id<<1|1] += lz[id];
        lz[id] = 0;
    }
    void upd(int i, int val, int id = 1, int l = 1, int r = n){
        if(l == r){
            st[id] = val;
            return;
        }
        push(id, l, r);
        int mid = l + r >> 1;
        if(i <= mid)upd(i, val, id<<1, l, mid);
        else upd(i, val, id<<1|1, mid+1, r);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    void add(int u, int v, int val, int id = 1, int l = 1, int r = n){
        if(l > v || r < u)return;
        if(u <= l && r <= v){
            st[id] += val;
            lz[id] += val;
            return;
        }
        push(id, l, r);
        int mid = l + r >> 1;
        add(u, v, val, id<<1, l, mid);
        add(u, v, val, id<<1|1, mid+1, r);
        st[id] = st[id<<1] + st[id<<1|1];
    }
    int query(int u, int v, int id = 1, int l = 1, int r = n){
        if(l > v or r < u)return 0;
        if(u <= l && r <= v)return st[id];
        push(id, l, r);
        int mid = l + r >> 1;
        return query(u, v, id<<1, l, mid) + query(u, v, id<<1|1, mid+1, r);
    }
    int get(int i, int id = 1, int l = 1, int r = n){
        if(l == r)return st[id];
        push(id, l, r);
        int mid = l + r >> 1;
        return i <= mid ? get(i, id<<1, l, mid) : get(i, id<<1|1, mid+1, r);
    }
};

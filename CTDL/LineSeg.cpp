struct IT{
    ii st[4*N];
    int cal(ii line, int x){
        return line.fi*x + line.se;
    }
    void upd(ii line, int id = 1, int l = 1, int r = n){
        if(l == r){
            if(cal(st[id], l) < cal(line, l))
                st[id] = line;
            return;
        }
        int mid = l + r >> 1;
        if(st[id].fi > line.fi)swap(st[id], line);
        if(cal(st[id], mid) < cal(line, mid)){
            swap(st[id], line);
            upd(line, id<<1, l, mid);
        }
        else upd(line, id<<1|1, mid+1, r);
    }
    void add(int u, int v, ii line, int id = 1, int l = 1, int r = n){
        if(l > v || r < u)return;
        if(u <= l && r <= v){
            upd(line, id, l, r);
            return;
        }
        int mid = l + r >> 1;
        add(u, v, line, id<<1, l, mid);
        add(u, v, line, id<<1|1, mid+1, r);
    }
    int get(int x, int id = 1, int l = 1, int r = n){
        if(l == r)return cal(st[id], x);
        int mid = l + r >> 1;
        if(x <= mid)return max(cal(st[id], x), get(x, id<<1, l, mid));
        return max(cal(st[id], x), get(x, id<<1|1, mid+1, r));
    }
}seg;

typedef long long ll;
const int N = 2e5 + 5;
const int S = log2(N)+1;
ll gilbertOrder(int x, int y){
    ll d = 0;
    for (int s = 1 << (S - 1); s; s >>= 1){
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry){
            if (rx){
                x = (1 << S) - x;
                y = (1 << S) - y;
            }
            swap(x, y);
        }
    }
    return d;
}
struct node{
    int l, r, i;
    ll ord;
    bool operator <(const node &a) const{
        return ord < a.ord;
    }
}q[N];
void add(int x){
    
}
void del(int x){
    
}
void solve(){
    FOR(i, 1, m){
        int l, r; cin >> l >> r;
        q[i] = {l, r, i, gilbertOrder(l, r)};
    }
    sort(q + 1, q + 1 + m);
    int l = 1, r = 0;
    FOR(i, 1, m){
        while(l < q[i].l)del(l++);
        while(l > q[i].l)add(--l);
        while(r < q[i].r)add(++r);
        while(r > q[i].r)del(r--);
        ans[q[i].i] = res;
    }
}

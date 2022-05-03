/// Do the solution on the paper
#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
#define int long long
#define rep(i, n) for(int i = 0;i < n;++i)
#define FOR(i, l, r) for(int i = l;i <= r;++i)
#define FOD(i, r, l) for(int i = r;i >= l;--i)
#define dem(x) __builtin_popcount(x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define SZ(x) (int)((x).size())
#define fi first
#define se second
typedef pair<int,int> ii;
//const int dx[4] = {-1, 0, 1, 0};
//const int dy[4] = {0, -1, 0, 1};
//const int base = 311;
//const int mod = 1e9 + 7;
const int N = 5e5 + 5;
const int M = 710;
int n, q, id[N], L[M], R[M], a[N], m, lz[M];
vector<ii> b[M];
void build(){
    int bl = sqrt(n);
    m = (n-1)/bl + 1;
    FOR(i, 1, m){
        L[i] = R[i-1] + 1;
        R[i] = min(n, i * bl);
        FOR(j, L[i], R[i]){
            b[i].pb({a[j], j});
            id[j] = i;
        }
        sort(all(b[i]));
    }
}
void add(int t, int l, int r, int x){
    for(auto &i : b[t])
        if(l <= i.se && i.se <= r)
            i.fi += x;
    sort(all(b[t]));
}
void upd(int l, int r, int x){
    FOR(i, id[l]+1, id[r]-1)lz[i] += x;
    if(id[l] != id[r]){
        add(id[l], l, R[id[l]], x);
        add(id[r], L[id[r]], r, x);
    }
    else add(id[l], l, r, x);
}
int get(int y){
    int l = 1e9, r = 0;
    FOR(i, 1, m){
        int u = lower_bound(all(b[i]), ii(y-lz[i], 0)) - b[i].begin();
        int v = upper_bound(all(b[i]), ii(y-lz[i], n)) - b[i].begin() - 1;
        if(u == SZ(b[i]) or b[i][u].fi != y-lz[i])continue;
        minn(l, b[i][u].se);
        maxx(r, b[i][v].se);
    }
    return l > r ? -1 : r - l;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(fopen("c.inp", "r")){
        freopen("c.inp", "r", stdin);
       // freopen("c.out", "w", stdout);
    }
    cin >> n >> q;
    FOR(i, 1, n)cin >> a[i];
    build();
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            upd(l, r, x);
        }
        else{
            int y; cin >> y;
            cout << get(y) << endl;
        }
    }
}

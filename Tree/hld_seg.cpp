/// https://cses.fi/problemset/task/2134/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n, sz[200005], q, d[200005], col[200005], cha[200005];
int head[200005], pos[200005], cnt, st[800005];
vector<int> a[200005];
void DFS(int u){
    sz[u] = 1;
    for(auto v : a[u])if(v != cha[u]){
        cha[v] = u;
        d[v] = d[u] + 1;
        DFS(v);
        sz[u] += sz[v];
    }
}
void update(int id,int l,int r,int i,int val){
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    if(i <= mid)update(id<<1, l, mid, i, val);
    else update(id<<1|1, mid+1, r, i, val);
    st[id] = max(st[id<<1], st[id<<1|1]);
}
void hld(int u,int top){
    pos[u] = ++cnt;
    head[u] = top;
    update(1, 1, n, cnt, col[u]);
    int best = - 1;
    for(auto v : a[u])if(v != cha[u])
        if(best == -1 or sz[v] > sz[best])best = v;
    if(best == -1)return;
    hld(best, top);
    for(int v : a[u])if(v != cha[u] && v != best)hld(v,v);
}
int query(int id,int l,int r,int u,int v){
    if(l > v or u > r)return 0;
    if(u <= l && r <= v)return st[id];
    int mid = l + r >> 1;
    return max(query(id<<1, l, mid, u, v), query(id<<1|1, mid+1, r, u, v));
}
int path(int u,int v){
    int res = 0;
    while(head[u] != head[v]){
        if(d[head[u]] < d[head[v]])swap(u,v);
        res = max(res, query(1, 1, n, pos[head[u]], pos[u]));
        u = cha[head[u]];
    }
    if(d[u] > d[v])swap(u,v);
    res = max(res, query(1, 1, n, pos[u], pos[v]));
    return res;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("c.INP","r",stdin);
    cin >> n >> q;
    for(int i = 1;i <= n;++i)cin >> col[i];
    for(int i = 1;i < n;++i){
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    DFS(1); hld(1, 1);
    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1)update(1, 1, n, pos[u], v);
        else cout << path(u,v) << " ";
    }
}

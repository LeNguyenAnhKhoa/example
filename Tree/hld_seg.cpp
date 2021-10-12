/// https://cses.fi/problemset/task/2134/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n, sz[200005], q, d[200005], c[200005], p[200005], head[200005], pos[200005], j;
vector<int> a[200005];
void DFS(int u){
    sz[u] = 1;
    for(auto v : a[u])if(v != p[u]){
        p[v] = u;
        d[v] = d[u] + 1;
        DFS(v);
        sz[u] += sz[v];
    }
}
struct IT{
    int st[400005];
    void add(int i,int val,int id = 1,int l = 1,int r = n){
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = l + r >> 1;
        if(i <= mid)add(i, val, id<<1, l, mid);
        else add(i, val, id<<1|1, mid+1, r);
        st[id] = max(st[id<<1], st[id<<1|1]);
    }
    int get(int u,int v,int id = 1,int l = 1,int r = n){
        if(l > v or r < u)return 0;
        if(u <= l && r <= v)return st[id];
        int mid = l + r >> 1;
        return max(get(u, v, id<<1, l, mid), get(u, v, id<<1|1, mid+1, r));
    }
}st;
void hld(int u,int top){
    pos[u] = ++j;
    head[u] = top;
    st.add(j, c[u]);
    int best = - 1;
    for(auto v : a[u])if(v != p[u])
        if(best == -1 or sz[v] > sz[best])best = v;
    if(best == -1)return;
    hld(best, top);
    for(auto v : a[u])if(v != p[u] && v != best)hld(v, v);
}
int path(int u,int v){
    int res = 0;
    while(head[u] != head[v]){
        if(d[head[u]] < d[head[v]])swap(u,v);
        res = max(res, st.get(pos[head[u]], pos[u]));
        u = p[head[u]];
    }
    if(d[u] > d[v])swap(u,v);
    res = max(res, st.get(pos[u], pos[v]));
    return res;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("c.INP","r",stdin);
    cin >> n >> q;
    for(int i = 1;i <= n;++i)cin >> c[i];
    for(int i = 1;i < n;++i){
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    DFS(1), hld(1, 1);
    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1)st.add(pos[u], v);
        else cout << path(u,v) << ' ';
    }
}

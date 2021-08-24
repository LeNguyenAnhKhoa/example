/// https://cses.fi/problemset/task/1139/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#include<tr1/unordered_map>
#define pb push_back
#define SZ(x) (int)((x).size())
int n, ans[200005], d[200005];
vector<int> a[200005];
Tree<int> s[200005];
void DFS(int u,int p){
    s[u].insert(d[u]);
    for(auto v : a[u])if(v != p){
        DFS(v,u);
        if(SZ(s[u]) < SZ(s[v]))s[u].swap(s[v]);
        for(auto i : s[v])s[u].insert(i);
    }
    ans[u] = SZ(s[u]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("c.inp","r",stdin);
    cin >> n;
    for(int i = 1;i <= n;++i)cin >> d[i];
    for(int i = 1;i < n;++i){
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    DFS(1,0);
    for(int i = 1;i <= n;++i)cout << ans[i] << " ";
}

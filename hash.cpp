#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SZ(x) (int)((x).size())
const ll mod = 1e9 + 7;
const ll base = 31;
int n, hsh[100005];
string s;
/// thay đổi kí tự ở vị trí vis từ from -> to và
/// tính hash mới của xâu độ dài n với has là hash cũ
ll trans(ll has,char from,char to,int vis,int n){
    ll d = (has + mod*mod - 1ll*(from - 'a' + 1) * pw[n-vis]) % mod;
    d = (d + 1ll*(to - 'a' + 1) * pw[n-vis]) % mod;
    return d;
}
/// tính hash đoạn [l..r]
ll cal(int l,int r){
    return (hsh[r] - hsh[l-1] * pw[r-l+1] + mod * mod) % mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("c.inp","r",stdin);
    cin >> s; n = SZ(s); s = ' ' + s; pw[0] = 1;
    for(int i = 1;i <= n;++i){
        pw[i] = (pw[i-1] * base) % mod;
        hsh[i] = (hsh[i-1] * base + s[i] - 'a' + 1) % mod;
    }
}

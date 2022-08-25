#define int long long
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int fac[N], n, ifac[N], C[N][N];
int cal(int x, int y){
    int res = 1;
    while(y){
        if(y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void init(){
    fac[0] = 1;
    for(int i = 1; i <= n; ++i)
        fac[i] = fac[i-1] * i % mod;
    ifac[n] = cal(fac[n], mod-2);
    for(int i = n; i >= 1; --i)
        ifac[i-1] = ifac[i] * i % mod;
    C[0][0] = 1;
    FOR(i, 1, n){
        C[i][0] = C[i][i] = 1;
        FOR(j, 1, i-1)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
}
int C(int n, int k){
    if(k > n)return 0;
    return fac[n] * ifac[n-k] % mod * ifac[k] % mod;
}

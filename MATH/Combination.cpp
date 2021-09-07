#define int long long
const int mod = 1e9 + 7;
int fac[100005], n, ifac[100005];
int pw(int a,int n){
    if(n == 1)return a;
    int tmp = pw(a, n/2);
    if(n&1)return tmp * tmp % mod * a % mod;
    return tmp * tmp % mod;
}
void init(){
    fac[0] = 1;
    for(int i = 1;i <= n;++i)fac[i] = fac[i-1] * i % mod;
    ifac[n] = pw(fac[n], mod-2);
    for(int i = n;i >= 1;--i)ifac[i-1] = ifac[i] * i % mod;
}
int C(int n,int k){
    return fac[n] * ifac[n-k] % mod * ifac[k] % mod;
}

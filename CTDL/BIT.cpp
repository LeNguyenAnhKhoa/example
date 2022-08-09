const int N = 1e5 + 5;
int n;
struct BIT{
    int bit[N];
    void add(int i, int x){
        if(i <= 0)return;
        for(; i <= n; i += i&-i)
            bit[i] += x;
    }
    int get(int i){
        int res = 0;
        for(; i > 0; i ^= i&-i)
            res += bit[i];
        return res;
    }
    int get(int l, int r){
        return get(r) - get(l-1);
    }
};

struct BIT{
    int bit[100005];
    void update(int i,int x){
        for(;i <= 1e5;i += i&-i)
            bit[i] += x;
    }
    int get(int i){
        int res = 0;
        for(;i > 0;i ^= i&-i)
            res += bit[i];
        return res;
    }
    int get(int l,int r){
        return get(r) - get(l-1);
    }
};

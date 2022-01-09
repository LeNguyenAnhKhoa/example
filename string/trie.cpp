#define SZ(x) (int)((x).size())
struct trie{
    struct node{
        int nx[26], leaf;
        node(){
            leaf = 0;
            rep(i, 26)
                nx[i] = 0;
        }
    };
    vector<node> a;
    trie() { a.pb(node()); }
    void add(string s){
        int cur = 0;
        for(auto c : s){
            int i = c - 'a';
            if(a[cur].nx[i] == 0){
                a[cur].nx[i] = SZ(a);
                a.pb(node());
            }
            cur = a[cur].nx[i];
        }
        a[cur].leaf = 1;
    }
    bool get(string s){
        int cur = 0;
        for(auto c : s){
            int i = c - 'a';
            if(!a[cur].nx[i])return 0;
            cur = a[cur].nx[i];
        }
        return 1;
    }
};

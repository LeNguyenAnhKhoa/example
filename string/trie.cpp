#define SZ(x) (int)((x).size())
struct trie{
    bool leaf;
    trie *nx[26];
    trie(){
        leaf = false;
        for(int i = 0;i < 26;++i)
            nx[i] = NULL;
    }
}*root;
void add(string s){
     trie *node = root;
     for(int i = 0;i < SZ(s);++i){
        if(node->nx[s[i]-'a'] == NULL)
            node->nx[s[i]-'a'] = new trie();
        node = node->nx[s[i]-'a'];
     }
     node->leaf = true;
}
bool tim(string s){
    trie* node = root;
    for(int i = 0;i < SZ(s);++i){
        if(node->nx[s[i]-'a'] == NULL)
            return false;
        node = node->nx[s[i]-'a'];
    }
    return true;
}

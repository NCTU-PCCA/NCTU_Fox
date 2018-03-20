// Maximum Cardinality Bipartite Matching
// Worst case O(nm)

struct Graph{ 
    static const int MAXN = 5003;
    vector<int> G[MAXN];
    int n, match[MAXN], vis[MAXN];

    void init(int _n){
        n = _n;
        for (int i=0; i<n; i++) G[i].clear();
    }

    bool dfs(int u){
        for (int v:G[u]){
            if (vis[v]) continue;
            vis[v]=true;
            if (match[v]==-1 || dfs(match[v])){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve(){
        int res = 0;
        memset(match,-1,sizeof(match));
        for (int i=0; i<n; i++){
            if (match[i]==-1){
                memset(vis,0,sizeof(vis));
                if ( dfs(i) ) res++;
            }
        }
        return res;
    }
} graph;

// Maximum Cardinality Matching

struct Graph {
  vector<int> G[MAXN];
  int pa[MAXN], match[MAXN], st[MAXN], S[MAXN], vis[MAXN];
  int t, n;

  void init(int _n) {
    n = _n;
    for ( int i = 1 ; i <= n ; i++ ) G[i].clear();
  }
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int lca(int u, int v){
    for ( ++t ; ; swap(u, v) ) {
      if ( u == 0 ) continue;
      if ( vis[u] == t ) return u;
      vis[u] = t;
      u = st[ pa[ match[u] ] ];
    }
  }
  void flower(int u, int v, int l, queue<int> &q) {
    while ( st[u] != l ) {
      pa[u] = v;
      if ( S[ v = match[u] ] == 1 ) {
        q.push(v);
        S[v] = 0;
      }
      st[u] = st[v] = l;
      u = pa[v];
    }
  }
  bool bfs(int u){
    for ( int i = 1 ; i <= n ; i++ ) st[i] = i;
    memset(S, -1, sizeof(S));
    queue<int>q; 
    q.push(u);
    S[u] = 0;
    while ( !q.empty() ) {
      u = q.front(); q.pop();
      for ( int i = 0 ; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if ( S[v] == -1 ) {
          pa[v] = u;
          S[v] = 1;
          if ( !match[v] ) {
            for ( int lst ; u ; v = lst, u = pa[v] ) {
              lst = match[u];
              match[u] = v;
              match[v] = u;
            }
            return 1;
          }
          q.push(match[v]);
          S[ match[v] ] = 0;
        } else if ( !S[v] && st[v] != st[u] ) {
          int l = lca(st[v], st[u]);
          flower(v, u, l, q);
          flower(u, v, l, q);
        }
      }
    }
    return 0;
  }
  int solve(){
    memset(pa, 0, sizeof(pa));
    memset(match, 0, sizeof(match));
    int ans = 0;
    for ( int i = 1 ; i <= n ; i++ )
      if ( !match[i] && bfs(i) ) ans++;
    return ans;
  }
} graph;

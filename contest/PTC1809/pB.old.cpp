#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000004;
int n;
bool eve[MAXN];
vector<int> ad[MAXN];
int par[MAXN];
int deg[MAXN];

int fa[MAXN];
int find(int x){
    if (fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}

bool ok;

void massert(bool b){
    if (b) return;

    cout << "what the fuck\n";
    exit(0);
}

void init(){
    ok=1;

    scanf("%d", &n);

    for (int i=0; i<n; i++){
        eve[i] = false;
        ad[i].clear();
        par[i] = deg[i] = 0;
    }
    int m; scanf("%d", &m);
    while (m--){
        int x; scanf("%d", &x);
        eve[x] = true;
    }

    for (int i=0; i<n; i++) fa[i] = i;
    
    for (int i=0; i<n-1; i++){
        int u, v; scanf("%d%d", &u, &v);
        massert( 0<=u && u<n );
        massert( 0<=v && v<n );

        ad[u].push_back(v);
        ad[v].push_back(u);

        u = find(u);
        v = find(v);
        if(u==v)ok=0;
        else fa[u] = v;
    }
}

void solve(){
    massert(ok);
    if (!ok){
        puts("-1");
        return;
    }
    vector<int> a;
    queue<int> que;
    que.push(0);
    fill(par,par+n,0);
    while (que.size()){
        int u = que.front(); que.pop();
        a.push_back(u);
        for (int v:ad[u]) if ( v!=par[u] ){
            par[v] = u;
            que.push(v);
        } 
    }

    for (int i=0; i<n; i++) deg[i] = ad[i].size()%2;

    int ans = n-1;
    for (int i=n-1; i>0; i--){
        int u = a[i];
        if ( deg[u] == eve[u] ){
            deg[u]^=1;
            deg[ par[u] ]^=1;
            ans--;
        }
    }
    if ( deg[0] == eve[0] || n>50000) puts("-1");
    else cout << ans << '\n';
}

int main (){
    int T; scanf("%d", &T);
    massert(0<=T);
    while (T--){
        init();
        solve();
    }
}

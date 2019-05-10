#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int n, m;
vector<int> G[MAXN];
int deg[MAXN];



void init(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

bool black[MAXN];

bool vis[MAXN];
vector<int> S;

void dfs_comp(int u){
    if ( vis[u] ) return;
    vis[u] = 1;

    S.push_back(u);
    for (int v:G[u]){
        dfs_comp(v);
    }
}

vector< pair<int,int> > ans;

void other(){
    queue<int> que;

    for (int u:S) if ( deg[u]==1 ) {
        que.push(u);
    }

    while (que.size()){
        int u = que.front(); que.pop();
        black[u] = 1;
        for (int v:G[u]){
            deg[v]--;
            if (deg[v]==1){
                que.push(v);
            }
        }
    } 

    for (int u:S){
        for (int v:G[u]){
            if ( black[u] && !black[v] ){
                ans.push_back( {v,u} );
            }
        }
    }
}

void isTree(){
    for (int u:S){
        if (deg[u]==1){
            ans.push_back( {u,G[u][0]} );
        }
    }
}

void solve(){
    for (int i=1; i<=n; i++) if (!vis[i]) {
        S.clear();
        dfs_comp(i);

        int sum = 0;
        for (int x:S) sum += deg[x];
        if ( sum+2 == (int)S.size()*2 ){
            // is tree
            isTree();
        }
        else {   
            // other case
            other();
        }
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    solve();

    cout << ans.size() << '\n';
    sort(ans.begin(),ans.end());
    for (auto p: ans){
        cout << p.first << ' ' << p.second << '\n';
    }
}

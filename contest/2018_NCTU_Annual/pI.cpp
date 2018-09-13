#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const int MAXN = 100005;

int n; long long a[MAXN]; int root;
vector<int> G[MAXN];

long long S_b[MAXN], CA_b[MAXN], CL_b[MAXN], SZ_b[MAXN];
long long S[MAXN], CA[MAXN], CL[MAXN], SZ[MAXN];

long long nor(long long x){
    x%=MOD;
    if (x<0) x+=MOD;
    return x;
}

void init(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &a[i]);

    for (int i=1; i<n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    root = rand()%n+1;
}

void dfs_1(int u, int fa){
    CL_b[u] = 1;
    SZ_b[u] = 1;
    CA_b[u] = a[u];
    S_b[u] = 0;
    
    for (int v:G[u]) if (v!=fa) {
        dfs_1(v,u);
        CL_b[u] = nor( CL_b[u] + CL_b[v] + SZ_b[v] );
        SZ_b[u] += SZ_b[v];
        CA_b[u] = nor( CA_b[u] + CA_b[v] + a[u] * SZ_b[v] );
        S_b[u] = nor( S_b[u] + S_b[v] + CA_b[v] + a[u]*CL_b[v] );
    }
}

void dfs(int u, int fa){
    for (int v:G[u]) if (v!=fa) {
        SZ[v] = n - SZ_b[v] + 1;
        CL[v] = nor( (CL[u] + SZ[u]) + (CL_b[u] -1 - CL_b[v] - SZ_b[v]) );

        dfs(v,u);
    }
}

int main(){
    init();
    root=1;

    dfs_1(root,root);

    SZ[root] = 1;
    CL[root] = 1;
    CA[root] = a[u];
    S[root] = 0;
    dfs(root,root);

    for (int i=1; i<=n; i++){
        printf("%lld ", S_b[i]);
    }
    long long ans = 0;
    for (int i=1; i<=n; i++){
    }
    cout << ans << '\n';
}

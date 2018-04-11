#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
int n;
vector<int> G[MAXN];
int h[MAXN];
int pre[MAXN];

void dfs(int u){
    h[u]=0;
    for (int v:G[u]){
        if (h[v]==-1) dfs(v);
        h[u] = max(h[u],h[v]+1);
    }
}

void dp(int u){
    for (int i=0, mx=1; i<G[u].size(); i++){
        int v = G[u][i];
        pre[v] = max(pre[v],mx);
        mx = max(mx,h[v]+2);
    }
    for (int i=G[u].size()-1, mx=1; i>=0; i--){
        int v = G[u][i];
        pre[v] = max(pre[v],mx);
        mx = max(mx,h[v]+2);
    }
    for (int v:G[u]){
        pre[v] = max(pre[v],pre[u]+1);
        dp(v);
    }
}

int main(){
    int T; cin >> T;
    while (T--){
        scanf("%d", &n);
        for (int i=1; i<n; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }
        fill(h+1,h+1+n,-1);
        memset(pre,-1,sizeof(pre));

        long long H=0;
        for (int i=1; i<=n; i++){
            if (h[i]==-1) dfs(i);
            H += h[i];
        }
        int root = max_element(h+1,h+1+n)-h;
        pre[root]=0;
        dp(root);
        long long R=0;
        for (int i=1; i<=n; i++){
            R += max( h[i], pre[i]);
        }
        printf("%lld %lld\n",H,R);
        for (int i=1; i<=n; i++) G[i].clear();
    }
}

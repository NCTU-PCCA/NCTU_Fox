#include <bits/stdc++.h>
using namespace std;

char getc(){
    static const int bufsize = 1<<16;
    static char B[bufsize], *S=B, *T=B;
    return (S==T&&(T=(S=B)+fread(B,1,bufsize,stdin),S==T)?0:*S++);
}

void input(int &a){
    scanf("%d",&a); return;
    a=0;
    register char p;
    while ( (p=getc())<'-' )
        if (p==0 || p==EOF) return;
    a=p^'0';
    while ( (p=getc()) >= '0' ) a = a*10 + (p^'0');
}

const int MAXN = 100005;
const int LG = 18;
int d[MAXN];
int h[MAXN];
int par[MAXN][LG];
int dp[MAXN][LG];

int n, m;
int vis[MAXN];
vector<int> G[MAXN];

void init(){
    input(n);
    for (int i=1, u, v; i<n; i++){
        input(u);
        input(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=1; i<=n; i++) input(d[i]);

    memset(vis,0,sizeof(vis));
    queue<int> que;
    que.push(1);
    vis[1]=1;
    par[1][0]=1;
    while ( que.size() ){
        int u = que.front(); que.pop();

        dp[u][0] = d[u];
        for (int i=1; i<LG; i++){
            par[u][i] = par[ par[u][i-1] ][i-1];
            dp[u][i] = max(dp[u][i-1], dp[ par[u][i-1] ][i-1] );
        }

        for (int v:G[u]){
            if ( vis[v] ) continue;
            par[v][0]=u;
            h[v] = h[u]+1;
            vis[v]=1;
            que.push(v);
        }
    }
}

int main(){
    //freopen("pE.in","r",stdin);
    int T;
    input(T);
    while (T--){
        init();
        for (int i=1; i<=n; i++) G[i].clear();
        input(m);
        while (m--){
            int u, v;
            input(u);
            input(v);
            int ans=(-1e9)-10;
            if (h[u]<h[v]) swap(u,v);
            // h[u] >= h[v]
            int dh = h[u]-h[v];
            for (int i=LG-1; i>=0; i--){
                if ( dh < (1<<i) )continue;
                dh -= (1<<i);
                ans = max( ans, dp[u][i] );
                u = par[u][i];
            }
            for (int i=LG-1; i>=0; i--){
                if ( par[u][i] == par[v][i] ) continue;
                ans = max( ans, dp[u][i]);
                ans = max( ans, dp[v][i]);
                u = par[u][i];
                v = par[v][i];
            }
            if (u!=v) ans = max(ans, d[ par[u][0] ] );
            ans = max(ans, d[ u ] );
            ans = max(ans, d[ v ] );

            printf("%d\n",ans);
        }
    }
}

/*
1
12
1 2
2 3
3 4
3 5
2 6
6 7
7 8
6 9
6 10
10 11
11 12
10 4 6 6 6 5 4 5 4 4 5 10
5
1 12
3 9
7 11
8 9
2 2

*/

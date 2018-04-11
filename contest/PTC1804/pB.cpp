#include <bits/stdc++.h>
using namespace std;

const int MAXM = 6003;
int n, m;
int E[MAXM][3], d[MAXM];

bool relax(){
    bool re=0;
    for (int i=0; i<n+m; i++){
        int u = E[i][0];
        int v = E[i][1];
        int w = E[i][2];
        if (d[u] > d[v]+w ){
            d[u] = d[v] + w;
            re=1;
        }
    }
    return re;
}

int main(){
    int T; cin >> T;
    while (T--){
        scanf("%d %d", &n, &m);
        for (int i=0; i<m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            E[i][0]=u;
            E[i][1]=v;
            E[i][2]=w;
        }

        for (int i=0; i<MAXM; i++) d[i]=1<<29;
        d[0]=0;
        for (int i=1; i<=n; i++){
            E[i-1+m][0] = 0;
            E[i-1+m][1] = i;
            E[i-1+m][2] = 0;
        }
        for (int i=0; i<=n; i++){
            relax();
        }
        if ( relax() ) puts("No");
        else puts("Yes");
    }
}

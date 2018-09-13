#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;
const int MAXM = 10004;
const double INF = 1e16;

struct Edge{
    int v, u;
    double c;
};

int n, m;
Edge e[MAXM];
double d[MAXN][MAXN];

void init(){
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--, v--;
        e[i].v = u;
        e[i].u = v;
        e[i].c = c;
    }
}

void BF(){
    for (int i=0; i<n; i++) d[0][i] = 0;
    for (int i=0; i<n; i++){
        fill(d[i+1],d[i+1]+n,INF);
        for (int j=0; j<m; j++){
            int v = e[j].v, u = e[j].u;
            if (d[i][v] < INF && d[i+1][u] > d[i][v] + e[j].c){
                d[i+1][u] = d[i][v] + e[j].c;
            }
        }
    }
}

void mmc(){
    double mmc = INF;
    BF();
    for (int i=0; i<n; i++){
        double avg = -INF;
        for (int k=0; k<n; k++){
            if (d[n][i]<INF) avg = max(avg,(d[n][i]-d[k][i])/(n-k));
            else avg = max(avg,INF);
        }
        mmc = min(mmc,avg);
    }
    printf("%.12f\n",mmc);
}

int main(){
    int T; cin >> T;
    while (T--){
        init();
        mmc();
    }
}

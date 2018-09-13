#include <bits/stdc++.h>
using namespace std;

const int MAXN = 202;
const int INF = 1<<29;

int n, a[MAXN][MAXN], d[MAXN][MAXN];

void init(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<2*n; i++){
        for (int j=0; j<2*n; j++){
            d[i][j] = INF;
            if (i%2!=j%2){
                if ( a[i/2][j/2] !=-1 )
                    d[i][j] = a[i/2][j/2];
            }
        }
    }
}

void solve(){
    for (int k=0; k<2*n; k++){
        for (int i=0; i<2*n; i++){
            for (int j=0; j<2*n; j++){
                d[i][j] = min( d[i][j], d[i][k]+d[k][j] );
            }
        }
    }
}
void output(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j] = d[i*2][j*2+1];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][j]==INF)a[i][j]=-1;
            printf("%d ",a[i][j]);
        }
        puts("");
    }
}
int main(){
    init();
    solve();
    output();
}

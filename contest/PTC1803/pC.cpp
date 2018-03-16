#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 5004;
const long long MOD = 1e9+7;
long long dp[N][N];

void build(){
    dp[0][0] = 1;
    for (int i=1; i<N; i++){
        for (int j=1; j<N; j++){
            dp[i][j] = (dp[i][j-1]*i%MOD + dp[i-1][j-1]*(j+1-i)%MOD)%MOD;
        }
    }
    for (int i=1; i<N; i++){
        for (int j=1; j<N; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
        }
    }
}

int main (){
    build();
    while (scanf("%d", &n) != EOF){
        int q;
        scanf("%d", &q);
        while (q--){
            scanf("%d", &k);
            printf("%lld ", dp[ min(k,n) ][n]);
        }
        printf("\n");
    }
}

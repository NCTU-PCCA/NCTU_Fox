#include <bits/stdc++.h>
using namespace std;

int n;
int la, ra;
int lb, rb;
int lc, rc;

int dp[31][130][130][50];

int main(){
    dp[0][0][0][0] = 1;

    scanf("%d", &n);
    scanf("%d %d", &la, &ra);
    scanf("%d %d", &lb, &rb);
    scanf("%d %d", &lc, &rc);

    for (int i=1; i<=n; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        for (int a=0; a<=ra; a++)for (int b=0; b<=rb; b++)for (int c=0; c<=rc; c++){
            dp[i][a][b][c] = dp[i-1][a][b][c];
        }

        for (int a=x; a<=ra; a++)for (int b=y; b<=rb; b++)for (int c=z; c<=rc; c++){
            dp[i][a][b][c] +=  dp[i-1][a-x][b-y][c-z];
        }
    }

    long long ans = 0;
    for (int a=la; a<=ra; a++)for (int b=lb; b<=rb; b++)for (int c=lc; c<=rc; c++){
        ans += dp[n][a][b][c];
    }
    cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;

int n, a[MAXN], dp[MAXN];
int din[MAXN];
vector<int> G[MAXN];

void init(){
    scanf("%d",&n);
    for (int i=0, u; i<n; i++){
        scanf("%d", &u);
        scanf("%d", &a[u]);
        int k; scanf("%d", &k);
        for (int j=0, v; j<k; j++){
            scanf("%d", &v);
            G[v].push_back(u);
            din[u]++;
        }
    }
}

int main(){
    init();
    queue<int> que;
    for (int i=0; i<n; i++){
        if (din[i]==0) que.push(i);
    }
    int ans=0;
    while (que.size()){
        int u = que.front(); que.pop();
        dp[u] += a[u];
        ans = max(ans, dp[u]);
        for (int v:G[u]){
            dp[v] = max(dp[v], dp[u]);
            din[v]--;
            if (din[v]==0) que.push(v);
        }
    }
    cout << ans <<'\n';
}

/*
5
0 199 4 1 2 3 4
1 935 0
2 879 2 1 3
3 522 0
4 146 2 1 3
*/

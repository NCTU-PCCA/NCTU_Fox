#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int LG = 20;

int n, K;
int par[MAXN][LG];

bool on_cyc[MAXN];
int cycl[MAXN], cycid[MAXN], cyczo[MAXN];
int din[MAXN];

vector<int> G[MAXN];

void init(){
    cin >> n >> K;
    for (int i=1; i<=n; i++){
        int v; cin >> v;
        par[i][0] = v;
        din[v]++;

        G[v].push_back(i);
    }
    for (int h=1; h<LG; h++){
        for (int i=1; i<=n; i++){
            par[i][h] = par[ par[i][h-1] ][h-1];
        }
    }
}

void find_trees(){
    fill(on_cyc+1, on_cyc+1+n, 1);

    queue<int> que;
    for (int i=1; i<=n; i++) if ( din[i]==0 ){
        que.push(i);
    }
    while (que.size()){
        int u = que.front(); que.pop();
        on_cyc[u] = 0;
        int v = par[u][0];
        din[v]--;
        if ( din[v]==0 ) que.push(v);
    }
}

void build_cycl(){
    fill( cycl+1, cycl+1+n, -1);
    fill( cycid+1, cycid+1+n, -1);
    for (int i=1; i<=n; i++){
        int w = par[i][19];
        if ( cycl[w]!=-1 ) continue;

        int len = 1;
        int v = par[w][0];
        int it = 0;
        cycid[w] = it++;
        cyczo[w] = w;
        while ( v!=w ) {
            cycid[v] = it++;
            cyczo[v] = w;
            len++;
            v = par[v][0];
        }
        cycl[w] = len;
        v = par[w][0];
        while( v!=w ){
            cycl[v] = len;
            v = par[v][0];
        }
    }
}

int subS[MAXN];

void solve(){
    for (int pi=1; pi<=n; pi++){
        int k = K;
        int w = pi;

        if ( !on_cyc[w] ){
            subS[w]++;
            for (int i=LG-1; i>=0; i--){
                if ( on_cyc[ par[w][i] ] ) continue;
                if ( (1<<i) > k ) continue;
                k -= (1<<i);
                w = par[w][i];
            } 
            if ( k==0 && !on_cyc[ par[w][0] ] ){
                subS[ par[w][0] ]--;
            }
            if ( k>0 ){
                k--;
                w = par[w][0];
            }
        }
        if ( !on_cyc[w] ) continue;
        
        int cl = cycl[w]; 
        int ci = cycid[w];

        if ( k>=cl ) subS[ cyczo[w] ]++;
        else {
            if ( ci+k >= cl ){
                // split
                subS[w]++;
                w = cyczo[w];
                k -= cl - ci;
            }
            subS[w]++;
            k++;
            for (int i=LG-1; i>=0; i--){
                if ( (1<<i) <= k ){
                    w = par[w][i];
                    k -= (1<<i);
                }
            }
            if ( cycid[w]!=0 ) subS[w]--;
        }
    }
}

bool vis[MAXN];

void dfs(int u){
    if ( vis[u] ) return;
    vis[u] = 1;

    for (int v:G[u]){ 
        dfs(v);
        subS[u] += subS[v];
    }
}


void parsum(){
    for (int i=1; i<=n; i++){
        if (!on_cyc[i]) {
            dfs(i);
        } else {
            if ( cycid[i]==0 ){
                int v = par[i][0];
                int sum = subS[i];
                while ( v!=i ){
                    sum += subS[v];
                    subS[v] = sum;
                    v = par[v][0];
                }
            }
        }
        
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    find_trees();
    build_cycl();
    solve();
    parsum();
    for (int i=1; i<=n; i++){
        cout << subS[i] << '\n';
    }
}

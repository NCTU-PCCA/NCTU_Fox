#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500004;
int scr[MAXN];
int cnt[MAXN];
bool vis[MAXN], _vis[MAXN];
vector<int> G[MAXN];
int RG[MAXN];
int n, m, s;
int S[26];
vector<int> scores, sides;

const int ii[] = {0, 1, 0,-1};
const int jj[] = {1, 0,-1, 0};
inline int dir(char c){
    switch(c){
        case 'u':
            return 3;
            break;
        case 'd':
            return 1;
            break;
        case 'r':
            return 0;
            break;
        case 'l':
            return 2;
            break;
        default:
            assert(false);
    }
}

void dfs(int now){
    cnt[now] = 0;
    vis[now] = true;
    for (int x : G[now])if(!vis[x]){
        scr[x] = scr[now];
        dfs(x);
        cnt[now] += cnt[x];
    }
    cnt[now] ++;
}

void find_loop(int now){
    while (true){
        _vis[now] = true;
        int next = RG[now];
        if (_vis[next]){
            scr[now] = 0;
            dfs(now);
            for (int i=next; i!=now; i=RG[i])
                cnt[i] = cnt[now];
            return;
        }
        now = next;
    }
}

void init(){
    static char buf[MAXN];
    scanf("%d%d%d", &n, &m, &s);
    for (int i=0; i<s; i++){
        scanf("%d", S+i);
    }
    scores.clear();
    sides.clear();
    for (int i=0; i<n*m; i++){
        G[i].clear();
        vis[i] = _vis[i] = false;
    }
    for (int i=0; i<n; i++){
        scanf("%s", buf);
        for (int j=0; j<m; j++){
            int now = i*m + j;
            if (buf[j] >= 'A' && buf[j] <= 'Z'){
                RG[now] = -2;
                scr[now] = S[buf[j]-'A'];
                scores.push_back(now);
            }
            else {
                int d = dir(buf[j]);
                int ni = i+ii[d];
                int nj = j+jj[d];
                if (ni>=0 && ni<n && nj>=0 && nj<m){
                    RG[now] = ni*m + nj;
                    G[ni*m + nj].push_back(now);
                }
                else {
                    RG[now] = -1;
                    scr[now] = 0;
                    sides.push_back(now);
                }
            }
        }
    }
    for (int x : scores) dfs(x);
    for (int x : sides ) dfs(x);
    for (int i=0; i<n*m; i++)
        if(!vis[i]) find_loop(i);
}

void solve(){
    long long ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) if(RG[i*m+j] >= -1){
            for (int k=0; k<4; k++){
                int ni = i+ii[k];
                int nj = j+jj[k];
                if (ni>=0 && ni<n && nj>=0 && nj<m && scr[ni*m+nj]>scr[i*m+j]){
                    ans = max(ans,
                            (long long)(scr[ni*m+nj] - scr[i*m+j]) * cnt[i*m+j]
                            );
                }
            }
        }
    }
    for (int x : scores) ans += (long long)cnt[x] * scr[x];
    printf("%lld\n", ans);
}

int main (){
    int T; scanf("%d", &T);
    while (T--){
        init();
        solve();
    }
}


#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll << 60;
const int MAXN = 1e5+4;

struct Dinic{
    struct Edge{
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];

    void init(){
        edges.clear();
        for (int i=0;i<MAXN;i++) G[i].clear();
    }

    void add_edge(int u, int v, long long cap){
        edges.push_back({u, v, cap, cap});
        edges.push_back({v, u, 0, 0ll});
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    bool bfs(){
        memset(d, -1, sizeof(d));
        queue<int> que;
        que.push(s); d[s] = 0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (int ei : G[u]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a){
        if (u == t || a == 0) return a;
        long long flow = 0, f;
        for (int &i = cur[u]; i<(int)G[u].size(); i++){
            Edge &e = edges[ G[u][i] ];
            if (d[u] + 1 != d[e.v]) continue;
            f = dfs(e.v, min(a, e.rest));
            if (f > 0){
                e.rest -= f;
                edges[ G[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    long long maxflow(int _s, int _t){
        this->s = _s; this->t = _t;
        long long flow = 0, mf;
        while ( bfs() ){
            memset(cur, 0, sizeof(cur));
            while((mf=dfs(s,INF))) flow += mf;
        }
        return flow;
    }
}dinic;

const int s = 1e5, t = 1e5+1;
int n, m;
int c[MAXN];
vector<int> ad[MAXN];
vector< pair<int,int> > edges;
bool vis[MAXN];
bool tag[MAXN];

void dfs(int now, bool _t){
    tag[now] = _t;
    vis[now] = true;
    for (int x : ad[now]) if (!vis[x])
        dfs(x, !_t);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;i++) scanf("%d", c+i);
    for (int i=0; i<m; i++){
        int u, v; scanf("%d%d", &u, &v);
        u --; v --;
        ad[u].push_back(v);
        ad[v].push_back(u);
        edges.push_back({u,v});
    }
    for (int i=0; i<n; i++) if(!vis[i]) dfs(i, 0);
    for (auto e:edges){
        int u = e.first, v = e.second;
        if ( tag[u] ) swap(u,v);
        dinic.add_edge(u, v, 1);
    }
    for (int i=0; i<n; i++){
        if (tag[i]){ // to sink
            dinic.add_edge(i, t, c[i]);
        }
        else { // from source
            dinic.add_edge(s, i, c[i]);
        }

    }
    cout <<m-dinic.maxflow(s, t) <<'\n';
}

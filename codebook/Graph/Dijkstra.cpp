struct Edge{
    int v; long long len;
    bool operator < (const Edge &b)const { return len>b.len; }
};

const long long INF = 1LL<<60;

void Dijkstra(int n, vector<Edge> G[], long long d[], int s, int t=-1){
    static priority_queue<Edge> pq;
    while ( pq.size() )pq.pop();
    for (int i=1; i<=n; i++)d[i]=INF;
    d[s]=0; pq.push( {s,d[s]} );
    while ( pq.size() ){
        auto x = pq.top(); pq.pop();
        int u = x.v;
        if (d[u]<x.len)continue;
        if (u==t)return;
        for (auto &e:G[u]){
            if (d[e.v] > d[u]+e.len){
                d[e.v] = d[u]+e.len;
                pq.push( {e.v,d[e.v]} );
            }
        }
    }
}

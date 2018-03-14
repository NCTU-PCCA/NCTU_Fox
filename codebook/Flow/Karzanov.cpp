const long long INF = 1LL<<60;

struct Karzanov{ // O(V*V*V)
    static const int MAXN = 5003;

    struct Edge{
        int v, w;
        long long u, f; // cap, flow
    };

    int n, m ,s, t, d[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
    int topo[MAXN], order[MAXN], topon;

    long long ex[MAXN];
    int cur[MAXN];
    bool forzon[MAXN];
    vector< pair<int,long long> > sta[MAXN]; // ei, f

    Karzanov() { init(); }

    void init( int _n = MAXN ){
        n = _n, m=0;
        edges.clear();
        for (int i=0; i<n; i++) G[i].clear();
    }

    void add_edge(int v, int w, long long u){
        edges.push_back( {v,w,u,0} );
        edges.push_back( {w,v,0,0} );
        m = edges.size();
        G[v].push_back(m-2);
        G[w].push_back(m-1);
    }

    long long max_flow(int _s, int _t){
        s=_s, t=_t;
        long long flow=0;
        while (bfs()) flow += blocking_flow();
        return flow;
    }

private:

    bool bfs(){
        fill(topo,topo+n,-1); topon=0;
        fill(order,order+n,-1);
        fill(d,d+n,-1);
        queue<int> que;
        que.push(s); d[s]=0;
        while ( !que.empty() ){
            int v = que.front(); que.pop();
            order[v] = topon;
            topo[topon++] = v;

            for (int ei:G[v]){ Edge &e = edges[ei];
                if ( d[e.w]<0 && e.f<e.u ){
                    d[e.w] = d[v]+1;
                    que.push(e.w);
                }
            }
        }
        return d[t]>=0;
    }

    void modify(int ei, long long df){
        Edge &e = edges[ei];
        ex[ e.v ] -= df;
        ex[ e.w ] += df;
        e.f += df;
        edges[ei^1].f -= df;
    }

    void push_step(){
        for (int i=0; i<topon; i++){
            int v = topo[i];
            for (int &j=cur[v]; j<(int)G[v].size(); j++){
                if (ex[v]==0)break;

                Edge &e = edges[ G[v][j] ];
                if ( forzon[e.w] || e.u==e.f || order[v]>=order[e.w] )continue;

                long long delta = min(ex[v],e.u-e.f);
                modify( G[v][j], delta );
                sta[ e.w ].push_back( {G[v][j],delta});
                if (e.f<e.u)break;
            }
        }
    }

    bool balancing_step(){
        for (int i=topon-1; i>0 ;i--) if (ex[ topo[i] ]>0){
            int w = topo[i];
            while (ex[w]>0){
                int ei = sta[w].back().first;
                long long delta = min( sta[w].back().second, ex[w] );
                modify( ei, -delta);
                sta[w].pop_back();
            }
            forzon[w]=1;
            return 1;
        }
        return 0;
    }

    long long blocking_flow(){
        fill(ex,ex+n,0);    
        fill(cur,cur+n,0);    
        fill(forzon,forzon+n,0);    
        for (int i=0; i<n; i++) sta[i].clear();

        long long flow = 0;
        ex[s] = INF;

        for (int i=0; i<n; i++){
            push_step();
            flow += ex[t]; ex[t]=0;
            if ( !balancing_step() )break;
        }

        return flow;
    }

} karzanov;

Construct of Gomory Hu Tree

1. make sure the whole graph is clear
2. set node 0 as root, also be the parent of other nodes.
3. for every node i > 0, we run maxflow from i to parent[i]
4. hense we know the weight between i and parent[i]
5. for each node j > i, if j is at the same side with i,
   make the parent of j as i
-------------------------------------------------------

int e[MAXN][MAXN];
int p[MAXN]; 

Dinic D; // original graph

void gomory_hu() {
    fill(p, p+n, 0);
    fill(e[0], e[n], INF);
    for ( int s = 1 ; s < n ; s++ ) {
        int t = p[s];
        Dinic F = D;
        int tmp = F.max_flow(s, t);

        for ( int i = 1 ; i < s ; i++ )
            e[s][i] = e[i][s] = min(tmp, e[t][i]);

        for ( int i = s+1 ; i <= n ; i++ ) 
            if ( p[i] == t && F.side[i] ) p[i] = s;

    }
}
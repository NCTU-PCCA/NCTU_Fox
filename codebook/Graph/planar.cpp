//skydog
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <climits>
#include <functional>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;

#define mp make_pair
#define pb push_back

#define debug(x) cerr << #x << " = " << x << " "

const int N=400+1;

struct Planar
{
    int n,m,hash[N],fa[N],deep[N],low[N],ecp[N];
    vector<int> g[N],son[N];
    set< pair<int,int> > SDlist[N],proots[N];
    int nxt[N][2],back[N],rev[N];
    deque<int> q;
    void dfs(int u)
    {
        hash[u]=1; q.pb(u);
        ecp[u]=low[u]=deep[u];
        int v;
        for (int i = 0; i < g[u].size(); ++i)
            if(!hash[v=g[u][i]])
            {
                fa[v]=u;
                deep[v]=deep[u]+1;
                dfs(v);
                low[u]=min(low[u],low[v]);
                SDlist[u].insert(mp(low[v],v));
            }
            else ecp[u]=min(ecp[u],deep[v]);
        low[u]=min(low[u],ecp[u]);
    }
    
    int visited[N];
    
    void addtree(int u,int t1,int v,int t2)
    {
        nxt[u][t1]=v; nxt[v][t2]=u;
    }
    
    void findnxt(int u,int v,int& u1,int& v1)
    {
        u1=nxt[u][v^1];
        if(nxt[u1][0]==u) v1=0;
        else v1=1;
    }
    
    void walkup(int u,int v)
    {
        back[v]=u;
        int v1=v,v2=v,u1=1,u2=0,z;
        for (;;)
        {
            if(hash[v1]==u || hash[v2]==u) break;
            hash[v1]=u;hash[v2]=u; z=max(v1,v2);
            if(z>n)
            {
                int p=fa[z-n];
                if(p!=u)
                {
                    proots[p].insert(mp(-low[z-n], z));
                    v1=p,v2=p,u1=0,u2=1;
                }
                else break;
            }
            else
            {
                findnxt(v1,u1,v1,u1);
                findnxt(v2,u2,v2,u2);
            }
        }
    }
    
    int topstack;
    pair<int,int> stack[N];
    
    int outer(int u,int v)
    {
        return ecp[v]<deep[u] || (SDlist[v].size() && SDlist[v].begin()->first<deep[u]);
    }
    
    int inside(int u,int v)
    {
        return proots[v].size()>0 || back[v]==u;
    }
    
    int active(int u,int v)
    {
        return inside(u,v) || outer(u,v);
    }
    
    void push(int a,int b)
    {
        stack[++topstack]=mp(a,b);
    }
    
    void mergestack()
    {
        int v1,t1,v2,t2,s,s1;
        v1=stack[topstack].first;t1=stack[topstack].second;
        topstack--;
        v2=stack[topstack].first;t2=stack[topstack].second;
        topstack--;
        
        s=nxt[v1][t1^1];
        s1=(nxt[s][1]==v1);
        nxt[s][s1]=v2;
        nxt[v2][t2]=s;
        
        SDlist[v2].erase( make_pair(low[v1-n],v1-n) );
        proots[v2].erase( make_pair(-low[v1-n],v1) );
    }
    
    void findnxtActive(int u,int t,int& v,int& w1,int S)
    {
        findnxt(u,t,v,w1);
        while(u!=v && !active(S,v))
            findnxt(v,w1,v,w1);
    }
    
    void walkdown(int S,int u)
    {
        topstack=0;
        int t1,v=S,w1,x2,y2,x1,y1,p;
        for(t1=0;t1<2;++t1)
        {
            findnxt(S,t1^1,v,w1);
            while(v!=S)
            {
                if(back[v]==u)
                {
                    while(topstack>0) mergestack();
                    addtree(S,t1,v,w1); back[v]=0;
                }
                if(proots[v].size())
                {
                    push(v,w1);
                    p=proots[v].begin()->second;
                    findnxtActive(p,1,x1,y1,u);
                    findnxtActive(p,0,x2,y2,u);
                    if(active(u,x1) && !outer(u,x1))
                        v=x1,w1=y1;
                    else if(active(u,x2) && !outer(u,x2))
                        v=x2,w1=y2;
                    else if(inside(u,x1) || back[x1]==u)
                        v=x1,w1=y1;
                    else v=x2,w1=y2;
                    push(p,v==x2);
                }
                else if(v>n || ( ecp[v]>=deep[u] && !outer(u,v) ))
                    findnxt(v,w1,v,w1);
                else if(v<=n && outer(u,v) && !topstack)
                {
                    addtree(S,t1,v,w1); break;
                }
                else break;
            }
        }
    }
    
    int work(int u)
    {
        int v;
        for (int i = 0; i < g[u].size(); ++i)
            if(fa[v=g[u][i]]==u)
            {
                son[u].push_back(n+v);
                proots[n+v].clear();
                addtree(n+v,1,v,0);
                addtree(n+v,0,v,1);
            }
        for (int i = 0; i < g[u].size(); ++i)
            if(deep[v=g[u][i]]>deep[u]+1)
                walkup(u,v);
        topstack=0;
        for (int i = 0; i < son[u].size(); ++i) walkdown(son[u][i], u);
        for (int i = 0; i < g[u].size(); ++i)
            if(deep[v=g[u][i]]>deep[u]+1 && back[v])
                return 0;
        return 1;
    }
    
    void init(int _n)
    {
        n = _n;
        m = 0;
        for(int i=1;i<=2*n;++i)
        {
            g[i].clear();
            SDlist[i].clear();
            son[i].clear();
            proots[i].clear();
            nxt[i][0]=nxt[i][1]=0;
            fa[i]=0;
            hash[i]=0;low[i]=ecp[i]=deep[i]=back[i]=0;
            q.clear();
        }
    }
    void add(int u, int v)
    {
        ++m;
        g[u].pb(v); g[v].pb(u);
    }
    bool check_planar()
    {
        if(m>3*n-5)
            return false;
        //  memset(hash,0,sizeof hash);
        for(int i=1;i<=n;++i)
            if(!hash[i])
            {
                deep[i]=1;
                dfs(i);
            }
        memset(hash,0,sizeof hash);
        //memset(hash, 0, (2*n+1)*sizeof(hash[0]));
        // originally only looks at last n element
        assert(q.size() == n);
        while (!q.empty())
        {
            if (!work(q.back()))
                return false;
            q.pop_back();
        }
        return true;
    }
} base, _new;
vector<ii> edges;
int n, m;
inline void build(int n, Planar &_new)
{
    _new.init(n);
    for (auto e : edges)
        _new.add(e.first, e.second);
}
void end()
{
    puts("-1");
    exit(0);
}
bool vis[N];
const int maxp = 5;
int path[maxp], tp=0;
void dfs(int cur)
{
    vis[cur] = true;
    path[tp++] = cur;
    if (tp == maxp)
    {
		auto it = lower_bound(base.g[cur].begin(), base.g[cur].end(), path[0]);
        if ( it != base.g[cur].end() && *it == path[0])
        {
            //a cycle
            int x = n+1;
            for (int i = 0; i < 5; ++i) edges.pb(mp(x, path[i]));
            build(x, _new);
            if (_new.check_planar())
            {
                for (int i = 0; i < maxp; ++i) printf("%d%c", path[i], i==maxp-1?'\n':' ');
                exit(0);
            }
            for (int i = 0; i < 5; ++i) edges.pop_back();
        }
    }
    else
    {
        for (auto e : base.g[cur]) if (!vis[e]) dfs(e);
    }
    vis[cur] = false;
    --tp;
}
int main()
{
    scanf("%d %d", &n, &m);
    if (n <= 4) 
      {
		  assert(false);
	puts("0"); return 0;
      }
    for (int i = 0; i < m; ++i)
		
    {
        int u, v; scanf("%d %d", &u, &v);
        edges.pb(mp(u, v));
    }
    build(n, base);
    if (!base.check_planar()) end();
    for (int i = 1; i <= n; ++i)
        sort(base.g[i].begin(), base.g[i].end());
    for (int i = 1; i <= n; ++i)
        dfs(i);
    end();
}



割點
點 u 為割點 if and only if 滿足 1. or 2. 
1. u 爲樹根，且 u 有多於一個子樹。 
2. u 不爲樹根，且滿足存在 (u,v) 爲樹枝邊 (或稱父子邊，即 u 爲 v 在搜索樹中的父親)，使得 DFN(u) <= Low(v)。

-------------------------------------------------------
橋
一條無向邊 (u,v) 是橋 if and only if (u,v) 爲樹枝邊，且滿足 DFN(u) < Low(v)。

// 0 base
struct TarjanSCC{
	static const int MAXN = 1000006;
	int n, dfn[MAXN], low[MAXN], scc[MAXN], scn, count;
	vector<int> G[MAXN];
	stack<int> stk;
	bool ins[MAXN];

	void tarjan(int u){
		dfn[u] = low[u] = ++count;
		stk.push(u);
		ins[u] = true;

		for(auto v:G[u]){
			if(!dfn[v]){
				tarjan(v);
				low[u] = min(low[u], low[v]);
			}else if(ins[v]){
				low[u] = min(low[u], dfn[v]);
			}
		}

		if(dfn[u] == low[u]){
			int v;
			do {
			v = stk.top();
			stk.pop();
			scc[v] = scn;
			ins[v] = false;
			} while(v != u);
			scn++;
		}
	}

	void getSCC(){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(ins,0,sizeof(ins));
		memset(scc,0,sizeof(scc));
		count = scn = 0;
		for(int i = 0 ; i < n ; i++ ){
			if(!dfn[i]) tarjan(i);
		}
	}

}SCC;

//lv紀錄深度
//father[多少冪次][誰]
//已經建好每個人的父親是誰 (father[0][i]已經建好)
//已經建好深度 (lv[i]已經建好)
void makePP(){
	for(int i = 1; i < 20; i++){
		for(int j = 2; j <= n; j++){
			father[i][j]=father[i-1][ father[i-1][j] ];
		}
	}
}
int find(int a, int b){
	if(lv[a] < lv[b]) swap(a,b);
	int need = lv[a] - lv[b];
	for(int i = 0; need!=0; i++){
		if(need&1) a=father[i][a];
		need >>= 1;
	}
	for(int i = 19 ;i >= 0 ;i--){
		if(father[i][a] != father[i][b]){
			a=father[i][a];
			b=father[i][b];
		}
	}
	return a!=b?father[0][a] : a;
}


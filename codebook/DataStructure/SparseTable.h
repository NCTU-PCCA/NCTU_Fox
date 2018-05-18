const int MAXN = 200005;
const int lgN = 20;

struct SP{ //sparse table
	int Sp[MAXN][lgN];
	function<int(int,int)> opt;
	void build(int n, int *a){ // 0 base
		for (int i=0 ;i<n; i++) Sp[i][0]=a[i];

		for (int h=1; h<lgN; h++){
			int len = 1<<(h-1), i=0;
			for (; i+len<n; i++)
				Sp[i][h] = opt( Sp[i][h-1] , Sp[i+len][h-1] );
			for (; i<n; i++)
				Sp[i][h] = Sp[i][h-1];
		}
	}
	int query(int l, int r){
		int h = __lg(r-l+1);
		int len = 1<<h;
		return opt( Sp[l][h] , Sp[r-len+1][h] );
	}
};

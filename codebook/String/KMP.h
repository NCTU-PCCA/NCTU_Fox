template<typename T>
void build_KMP(int n, T *s, int *f){ // 1 base
	f[0]=-1, f[1]=0;
	for (int i=2; i<=n; i++){
		int w = f[i-1];
		while (w>=0 && s[w+1]!=s[i])w = f[w];
		f[i]=w+1;
	}
}

template<typename T>
int KMP(int n, T *a, int m, T *b){
	build_KMP(m,b,f);
	int ans=0;

	for (int i=1, w=0; i<=n; i++){
	  while ( w>=0 && b[w+1]!=a[i] )w = f[w];
		w++;
		if (w==m){
			ans++;
			w=f[w];
		}
	}
	return ans;
}

// FWHT template

const int MAXN = 1<<20;

void FWHT(int a[], int l=0, int r=MAXN-1){
	if (l==r)return;

	int mid = (l+r)>>1+1, n = r-l+1;
	FWHT(a,l,mid-1);
	FWHT(a,mid,r);

	for (int i=0; i<(n>>1); i++){
		int a1=a[l+i], a2=a[mid+i];
		a[l+i] = a1+a2;
		a[mid+i] = a1-a2;
	}
}

// N is power of 2
template<typename Iter>
void DC(int N, Iter tmp, Iter A, Iter B, Iter res){
    if (N==1){
        res[0] = A[0]*B[0];
        return;
    }
    fill(res,res+2*N,0);
    int n = N/2;
    auto a = A+n, b = A;
    auto c = B+n, d = B;
    DC(n,tmp+N,a,c,res+2*N);
    for (int i=0; i<N; i++){
        res[i+N] += res[2*N+i];
        res[i+n] -= res[2*N+i];
    }
    DC(n,tmp+N,b,d,res+2*N);
    for (int i=0; i<N; i++){
        res[i] += res[2*N+i];
        res[i+n] -= res[2*N+i];
    }

    auto x = tmp;
    auto y = tmp+n;
    for (int i=0; i<n; i++) x[i] = a[i]+b[i];
    for (int i=0; i<n; i++) y[i] = c[i]+d[i];
    DC(n,tmp+N,x,y,res+2*N);
    for (int i=0; i<N; i++){
        res[i+n] += res[2*N+i];
    }
}

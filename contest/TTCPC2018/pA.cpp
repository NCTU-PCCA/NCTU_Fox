#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

struct Mat{
    vector< vector<int> > A;

    Mat(){
        A.resize( 4, vector<int>(4,0) );
        for (int i=0; i<4; i++) A[i][i]=1;
    }
    Mat operator * (const Mat &b) const{
        Mat re;
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                re.A[i][j]=0;
                for (int k=0; k<4; k++){
                    re.A[i][j] += (long long)A[i][k] * b.A[k][j] %MOD;
                    re.A[i][j] %= MOD;
                }
            }
        }
        return re;
    }
};

Mat pow(Mat A, long long n){
    Mat re;
    while (n>0){
        if (n&1) re = re*A;
        A = A*A;
        n>>=1;
    }
    return re;
}

long long n;
int a1, a2, b1, w, x, y, z;
int a[10], b[10];
Mat TM;

void init(){
    scanf("%lld %d %d %d %d %d %d %d", &n, &a1, &a2, &b1, &w, &x, &y, &z);
    TM = Mat();
    TM.A[0][0]=0, TM.A[0][1]=x, TM.A[0][2]=w;
    TM.A[1][0]=1, TM.A[1][1]=0, TM.A[1][2]=0;
    TM.A[2][0]=y, TM.A[2][1]=0, TM.A[2][2]=z;
    TM.A[3][0]=y, TM.A[3][1]=x, TM.A[3][2]=(w+z)%MOD;
    a[1] = a1; a[2] = a2;
    b[1] = b1; b[2] = ( (long long)y*a[1]%MOD + (long long)z*b[1]%MOD ) %MOD;
    for (int i=3; i<10; i++){
        a[i] = (w*b[i-1] + x*a[i-2])%MOD;
        b[i] = (y*a[i-1] + z*b[i-1])%MOD;
    }
    for (int i=1; i<10; i++){
        //printf("%d %d\n", a[i], b[i]);
    }
    if (n==1){
        cout << (a[1]+b[1])%MOD << '\n';
    }
    else {
        Mat M = pow(TM,n-2);
        int S = ((long long)a[1]+a[2]+b[1]+b[2])%MOD;
        long long ans = (long long)M.A[3][0]*a[2]%MOD + (long long)M.A[3][1]*a[1]%MOD + (long long)M.A[3][2]*b[2]%MOD + (long long)M.A[3][3]*S%MOD;
        ans %= MOD;
        cout << ans << '\n';
    }
}

int main(){
    int T; cin >> T;
    while (T--){
        init();
    }
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;
int n, a[MAXN];
bitset<MAXN> f[MAXN][MAXN];
int dp[2][MAXN][MAXN];
int posj, posk;
auto pre = dp[0], now = dp[1];

void init(){
    cin >> n;
    assert(1<=n && n <= 511);
    for (int i=1; i<=n; i++){
        cin >> a[i];
        assert(a[i]>=0 && a[i]<=511);
    }
}

int build_dp(){
    pre = dp[0];
    now = dp[1];
    for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) f[0][j][k] = 0;
    for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) pre[j][k] = -1, now[j][k] = -1;

    f[0][0][0] = 1;

    for (int i=1; i<=n; i++){
        for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) f[i][j][k] = 0;
        for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) now[j][k] = -1;

        for (int j=0; j<512; j++){
            for (int k=0; k<512; k++){
                if ( f[i-1][j][k] ){
                    f[i][ j^a[i] ][k] = 1;
                    f[i][j][ k|a[i] ] = 1;
                }
                if ( f[i-1][j][k] ){
                    now[j][k] = max( now[j][k], a[i] );
                }
                if ( pre[j][k]!=-1 ){
                    now[j^a[i]][k] = max( now[j^a[i]][k], pre[j][k] );
                    now[j][k|a[i]] = max( now[j][k|a[i]], pre[j][k] );
                }
            }
        }
        swap(pre,now);
    }
    swap(pre,now);

    int ans = -1;
    for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++){
        if ( now[j][k]!=-1 ){
            if ( ans < j+k+now[j][k] ){
                ans = j+k+now[j][k];
                posj = j;
                posk = k;
            }
        }
    }
    return ans;
}

vector<int> A, B, C;

void recover_f(int I, int J, int K){
    if (I<=0) return;

    /*
        if ( f[i-1][j][k] ){
            f[i][ j^a[i] ][k] = 1;
            f[i][j][ k|a[i] ] = 1;
        }
     */
    int i = I;
    for (int j=0; j<512; j++){
        for (int k=0; k<512; k++){
            if ( f[i-1][j][k] && (j^a[i])==J && k==K ){
                A.push_back(a[i]);
                recover_f(i-1,j,k);
                return;
            }
            if ( f[i-1][j][k] && j==J && (k|a[i])==K ){
                B.push_back(a[i]);
                recover_f(i-1,j,k);
                return;
            }
        }
    }
}

int main(){
    init();
    cout << build_dp() << '\n';

    for (int i=1; i<=n; i++){
        if ( now[posj][posk] == a[i] ){
            swap(a[i],a[n]);
            C.push_back(a[n]);
            n--;
            break;
        }
    }
    int pre_posj = posj;
    int pre_posk = posk;

    build_dp();
    recover_f(n,pre_posj,pre_posk);

    if(A.size()+B.size()+C.size()!=n+1){
        while(1);
    }
    cout << A.size();
    for (int x:A) cout << ' ' << x;
    cout << '\n';
    cout << B.size();
    for (int x:B) cout << ' ' << x;
    cout << '\n';
    cout << C.size();
    for (int x:C) cout << ' ' << x;
    cout << '\n';
}

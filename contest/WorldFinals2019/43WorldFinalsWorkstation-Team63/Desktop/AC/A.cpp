#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int INF = 1e8;
const int MAXN = 500005;
tuple<int,int,int> a[2][MAXN];

int n;

void init(){
    cin >> n;
    for (int j=0; j<2; j++){
        for (int i=0; i<n; i++) cin >> get<0>(a[j][i]);
        for (int i=0; i<n; i++) cin >> get<1>(a[j][i]);
        for (int i=0; i<n; i++) get<2>(a[j][i]) = i;
    }
    sort( a[0], a[0] + n);
    sort( a[1], a[1] + n);
}

void imp() {
    cout << "impossible" << endl;
    exit(0);
}

vector<int> ans[2];

void solve(){
    set< pii > L, R;
    int ptrL=0, ptrR=0;

    while ( ptrL<n || ptrR<n ){
        if ( L.empty() ){
            int pric = get<0>(a[0][ptrL]);
            while ( ptrL<n && get<0>(a[0][ptrL])== pric ){
                L.insert( {get<1>(a[0][ptrL]), get<2>(a[0][ptrL])+1} );
                ptrL++;
            }
        }
        if ( R.empty() ){
            int pric = get<0>(a[1][ptrR]);
            while ( ptrR<n && get<0>(a[1][ptrR]) == pric ){
                R.insert( {get<1>(a[1][ptrR]), get<2>(a[1][ptrR])+1} );
                ptrR++;
            }
        }
        assert( !L.empty() && !R.empty() );
        if ( L.size() < R.size() ){
            // pop_small(L,R,0,1);
            for (pii p : L) {
                auto it = R.lower_bound({ p.first, -1 });
                if (it == R.begin()) imp();
                it--;
                ans[0].push_back(p.second);
                ans[1].push_back(it->second);
                R.erase(it);
            }
            L.clear();
        }
        else {
            // pop_small(R,L,1,0);
            for (pii p : R) {
                auto it = L.upper_bound({ p.first, INF });
                if (it == L.end()) imp();
                ans[0].push_back(it->second);
                ans[1].push_back(p.second);
                L.erase(it);
            }
            R.clear();
        }
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    solve();

    assert((int)ans[0].size() == n);
    assert((int)ans[1].size() == n);

    for (int i=0; i<n; i++) cout << ans[0][i] << ' ';
    cout << endl;
    for (int i=0; i<n; i++) cout << ans[1][i] << ' ';
    cout << endl;
}

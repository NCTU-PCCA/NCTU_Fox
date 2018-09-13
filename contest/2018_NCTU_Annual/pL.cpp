#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int T; cin >>T;
    while(T--){
        long long a, b, c, d, e ,f ,g, h, i;
        cin >>a>>b>>c>>d>>e>>f>>g>>h>>i;
        cout << a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h <<' ';
        cout << a*e*i + b*f*g + c*d*h + c*e*g + b*d*i + a*f*h <<'\n';
    }
}

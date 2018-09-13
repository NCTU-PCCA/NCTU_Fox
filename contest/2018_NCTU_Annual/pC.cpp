#include <bits/stdc++.h>
using namespace std;

string a[3];

bool comp(const string& l, const string& r){
    if (l.size()!=r.size()) return l.size() > r.size();
    return l < r;
}

bool check(){
    const string& l = a[1];
    const string& r = a[2];
    size_t p = 0;
    for (char x : r){
        while (p < l.size() && l[p] != x) p++;
        if (p == l.size()) return false;
        p++;
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i=0; i<3; i++) cin >>a[i];
    //for (int i=0; i<3; i++) cout <<a[i] <<'\n';;
    sort(a, a+3, comp);
    if (a[0] != a[1]){
        cout <<a[0].size() <<'\n';
    }
    else if (!check()){
        cout <<a[2].size() <<'\n';
    }
    else cout <<0 <<'\n';
}

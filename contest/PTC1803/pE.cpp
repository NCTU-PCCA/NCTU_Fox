#include<set>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

struct event{
    bool is_start;
    int ind;
    double pos;
    bool operator<(const event& rhs) const{
        if (pos != rhs.pos) return pos < rhs.pos;
        return !is_start;
    }
};

struct data{
    double xl, yl, xr, yr;
    double lenPerx, yPerx;
    int c;
} a[300005];

int n, r;
double col[10004];
vector<event> ev;

struct comp{
    bool operator()(int lhs, int rhs)const{
        if (a[lhs].xl < a[rhs].xl){
            double tmp = a[lhs].yl + (a[rhs].xl - a[lhs].xl) * a[lhs].yPerx;
            return tmp > a[rhs].yl;
        }
        else {
            double tmp = a[rhs].yl + (a[lhs].xl - a[rhs].xl) * a[rhs].yPerx;
            return tmp < a[lhs].yl;
        }
    }
};

set<int,comp> s;

void solve(){
    double last_pos;
    for (auto& x : ev){
        if (s.size()){
            int ind = *s.begin();
            col[a[ind].c] += (x.pos - last_pos) * a[ind].lenPerx;
            last_pos = x.pos;
        }
        else last_pos = a[x.ind].xl;
        if (x.is_start) s.insert(x.ind);
        else s.erase(x.ind);
    }
}

int main (){
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &n,&r);
        fill(col, col+10004, 0);
        ev.clear();
        s.clear();
        for (int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf%d", &a[i].xl, &a[i].yl, &a[i].xr, &a[i].yr, &a[i].c);
            if (a[i].xl == a[i].xr){
                n--;
                i--;
                continue;
            }
            a[i].c --;
            if (a[i].xl > a[i].xr){
                swap(a[i].xl, a[i].xr);
                swap(a[i].yl, a[i].yr);
            }
            double xx = a[i].xl - a[i].xr;
            double yy = a[i].yl - a[i].yr;
            a[i].lenPerx = sqrt(xx*xx + yy*yy) / abs(xx);
            a[i].yPerx = yy / xx;
            ev.push_back({true,i,a[i].xl});
            ev.push_back({false,i,a[i].xr});
        }
        sort(ev.begin(), ev.end());
        solve();
        sort(col, col+r);
        printf("%.2f %.2f %.2f\n", col[0], col[(r+1)/2-1], col[r-1]);
    }
}

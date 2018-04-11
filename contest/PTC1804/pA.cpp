#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b==0)return a;
    return gcd(b,a%b);
}

struct vec{
    long long x,y;
    vec operator-(const vec& r)const{
        return {x-r.x,y-r.y};
    }
    bool operator<(const vec& r)const{
        if(x!=r.x)return x<r.x;
        return y<r.y;
    }
};

vec vecgcdx(vec a, vec b){
    if(a.x<b.x)swap(a,b);
    if(b.x==0)return b;
    auto d = a.x/b.x;
    b.x*=d;
    b.y*=d;
    a = a -b;
    return a;
}
vec vecgcdy(vec a, vec b){
    if(a.y<0){
        a.x*=-1;
        a.y*=-1;
    }
    if(b.y<0){
        b.x*=-1;
        b.y*=-1;
    }
    if(a.y<b.y)swap(a,b);
    if(b.y==0)return b;
    auto d = a.y/b.y;
    b.x*=d;
    b.y*=d;
    a = a -b;
    if(a.x<0){
        a.x*=-1;
        a.y*=-1;
    }
    return a;
}
set<vec> s;
vector<vec> v;
double dis(vec x){
    return sqrt(x.x*x.x+x.y*x.y);
}
void grob(){
    queue<pair<int,int>> q;
    for(int i = 0 ; i < (int)v.size() ; i ++){
        for(int j = i+1 ; j < (int)v.size() ; j ++){
            q.push({i,j});
        }
    }
    while(q.size()){
        auto now = q.front();
        q.pop();
        int i = now.first;
        int j = now.second;
        if(v[i].x!=0||v[j].x!=0){
            auto tmp = vecgcdx(v[i],v[j]);
            if(s.count(tmp)==0&&dis(tmp)<dis(v[i])&&dis(tmp)<dis(v[j])){
                s.insert(tmp);
                for(int ii = 0 ; ii < (int)v.size() ; ii ++){
                    q.push({ii,(int)v.size()});
                }
                v.push_back(tmp);
            }
        }
        if(v[i].y!=0||v[j].y!=0){
            auto tmp = vecgcdy(v[i],v[j]);
            if(s.count(tmp)==0&&dis(tmp)<dis(v[i])&&dis(tmp)<dis(v[j])){
                s.insert(tmp);
                for(int ii = 0 ; ii < (int)v.size() ; ii ++){
                    q.push({ii,(int)v.size()});
                }
                v.push_back(tmp);
            }
        }
    }
}

int main(){
    int T; cin >> T;
    while (T--){
        s.clear();
        v.clear();
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if(x<0){x*=-1;y*=-1;}
        v.push_back({x,y});
        s.insert({x,y});
        scanf("%lld%lld",&x,&y);
        if(x<0){x*=-1;y*=-1;}
        v.push_back({x,y});
        s.insert({x,y});
        grob();
        double ans = sqrt(double(x*x+y*y));
        for(const auto ve:v){
            if(ve.x==0&&ve.y==0)continue;
            ans= min(ans,sqrt(double(ve.x*ve.x+ve.y*ve.y)));
        }
        printf("%.2f\n",ans);
    }
}

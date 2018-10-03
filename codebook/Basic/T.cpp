#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;

void setstack(){
    // Set soft limit and hard limit to max
    const rlimit tmp {RLIM_INFINITY,RLIM_INFINITY};
    setrlimit(RLIMIT_STACK,&tmp);
}

int main(){
    #define name ""
    #ifndef FOX
    freopen(name".in","r",stdin);
    freopen(name".out","w",stdout);
    #endif
    static_assert(strlen(name));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}

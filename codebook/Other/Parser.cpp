#include <bits/stdc++.h>
using namespace std;

typedef long long T;
bool GG;

T Eval2(char *&end) {
    T Eval0(char *&);
    T res=0;
    if ( *end=='(' ){
        res = Eval0(++end);
        if (*(end++)==')') return res;
        else { GG = true; return -1; }
    }
    else if( isdigit(*end) ){
        return strtol(end, &end, 10);
    }   // 可改成  {strtol ,strtoll strtod}
    else { GG = true; return -1; }
}

T Evalx(char *&end){
    if(GG) return -1;
    T res = Eval2(end); if(GG) return -1;
    while (*end == '%'){
        end++;
        res = ( res % Eval2(end) );
        if(GG) return -1;
    }
    return res;
}

T Eval1(char *&end) {
    if(GG) return -1;
    T res = Evalx(end); if(GG) return -1;
    while (*end=='*' || *end == '/'){
        end++;
        if(*(end-1) == '*')res = ( res * Evalx(end) );
        else if(*(end-1) == '/')res = ( res / Evalx(end) );
        if(GG) return -1;
    }
    return res;
}

T Eval12(char *&end){
    if(GG) return -1;
    T res=1;
    if(*end == '-'){
        end++;
        res = -1;
    }
    res *= Evalx(end);
    while (*end=='*' || *end == '/'){
        end++;
        if(*(end-1) == '*')res = ( res * Evalx(end) );
        else if(*(end-1) == '/')res = ( res / Evalx(end) );
        if(GG) return -1;
    }
    return res;
}
T Eval0(char *&end) {
    if(GG) return -1;
    T res;
    res = Eval12(end); if(GG) return -1;
    while (*end=='+' || *end == '-'){
        end++;
        if(*(end-1) == '+')res = ( res + Eval1(end) );
        else res = ( res - Eval1(end) );
        if(GG) return -1;
    }
    return res;
}

T parse(char *s){
    GG = false;
    T res = Eval0(s);
    while(*s != '\0'){
        if(*s != ' ')GG = true;
        s++;
    }
    return res;
}

int main() {
    char expr[3003];
    string str;
    int cnt = 0;
    while (getline (cin,str)){
        printf("case %d:\n",++cnt);
        strcpy(expr,str.c_str());
        T ans = parse(expr);
        if(GG) puts("syntactically incorrect\n");
        else printf("%lld\n\n", ans);
    }
}

/*
E0 = E1' (+-E1)*
E1 = Ex (/*Ex)*
Ex = E2 (%E2)*
E2 = (E0) or R+
E1' = Ex (/* Ex)*  or  -Ex (/* Ex)*

*/

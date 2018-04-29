#include <bits/stdc++.h>
using namespace std;

char name[100];
array<int,9> numw,numb,numt;
int cntw,cntb,cntt;
int ee,ss,ww,nn,rc,gf,wb;
void init(){
    fill(numw.begin(),numw.end(),0);
    fill(numb.begin(),numb.end(),0);
    fill(numt.begin(),numt.end(),0);
    ee=0,ss=0,ww=0,nn=0,rc=0,gf=0,wb=0;
    cntw=0,cntb=0,cntt=0;
    scanf("%s",name);
    for(int i = 0 ; i < 17 ; i ++){
        string tmp;
        cin >> tmp;
        if(tmp[0]>='0'&&tmp[0]<='9'){
            int num=tmp[0]-'1';
            if(tmp[1]=='W'){
                cntw++;
                numw[num]++;
            }
            else if(tmp[1]=='B'){
                cntb++;
                numb[num]++;
            }
            else{
                cntt++;
                numt[num]++;
            }
        }
        else if(tmp=="EE"){
            ee++;
        }
        else if(tmp=="SS"){
            ss++;
        }
        else if(tmp=="WW"){
            ww++;
        }
        else if(tmp=="NN"){
            nn++;
        }
        else if(tmp=="RC"){
            rc++;
        }
        else if(tmp=="GF"){
            gf++;
        }
        else{
            wb++;
        }
    }
}
void check32(){
    int cnt[3]={0};
    cnt[ee%3]++;
    cnt[ss%3]++;
    cnt[ww%3]++;
    cnt[nn%3]++;
    cnt[rc%3]++;
    cnt[gf%3]++;
    cnt[wb%3]++;
    cnt[cntw%3]++;
    cnt[cntb%3]++;
    cnt[cntt%3]++;
    //printf("!!! %d %d %d\n",cnt[0],cnt[1],cnt[2]);
    if(cnt[0]!=9)throw 0;
    if(cnt[2]!=1)throw 0;
}


bool realcheck(array<int,9> a){
    int minv=10;
    for(int i = 0 ; i < 9 ; i ++){
        if(a[i]!=0){
            minv=i;
            break;
        }
    }
    if(minv==10)return true;
    if(a[minv]>=3){
        a[minv]-=3;
        if(realcheck(a))return true;
        a[minv]+=3;
    }
    if(minv<=6&&a[minv+1]>=1&&a[minv+2]>=1){
        a[minv]--;
        a[minv+1]--;
        a[minv+2]--;
        if(realcheck(a))return true;
        a[minv]++;
        a[minv+1]++;
        a[minv+2]++;
    }
    return false;
}

void check(array<int,9> a,int total){
    if(total%3==2){
        for(int i = 0 ; i < 9 ; i ++){
            if(a[i]>=2){
                a[i]-=2;
                if(realcheck(a))return;
                a[i]+=2;
            }
        }
        throw 0;
    }
    else{
        if(!realcheck(a))throw 0;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        bool ok=true;
        try{
            check32();
            check(numb,cntb);
            check(numt,cntt);
            check(numw,cntw);
        }
        catch(...){
            ok=false;
        }
        if(ok)printf("%s can yell out Mahjong!\n",name);
        else printf("Nothing happened.\n");
    }
}
/*
2
Capoo
1W 1W 1W 2W 2W 4W 4W 4W 3T 4T 5T 7T 8T 9T GF GF GF
DogDog
1B 2B 2B 2B 3B 3B 3B 4B 4B 1T 1T 1T 1T WW WW WB WB
*/

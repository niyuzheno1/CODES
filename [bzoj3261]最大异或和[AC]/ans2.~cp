/**************************************************************
    Problem: 3261
    User: OceanLight
    Language: C++
    Result: Accepted
    Time:4228 ms
    Memory:294360 kb
****************************************************************/
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <queue>
#include "mode.h"
#undef CLEAR
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALLL(x) x.begin(),x.end()
#define SORT(x) sort(ALLL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILLL(x,c) memset(x,c,sizeof(x))
using namespace std;
const double eps = 1e-9;
#define LL long long
#define pb push_back
const int maxn  = 610000;
int a[maxn],b[maxn];
struct Node{
   Node *s[2];
   int sum;
}nodes[maxn*40];
Node *root[maxn],*null;
int C;
int n,m;
void init(){
    C=0;
    root[0] = null = &nodes[C++];
    null->s[0] = null->s[1] = null;
    null->sum = 0;
}
Node *insert(int v,int d,Node *root){
     Node *rt = &nodes[C++];
     rt->s[0] = root->s[0];
     rt->s[1] = root->s[1];
     rt->sum = root->sum+1;
     if(d<0)return rt;
     int p = (v>>d)&1;
     rt->s[p] = insert(v,d-1,root->s[p]);
     return rt;
}
int query(int v,int d,Node *rt1,Node *rt2){
    if(d<0)return 0;
    int p = (v>>d)&1;
    if(rt2->s[p^1]->sum - rt1->s[p^1]->sum){
          return (1<<d)+query(v,d-1,rt1->s[p^1],rt2->s[p^1]);
    }
    return query(v,d-1,rt1->s[p],rt2->s[p]);
}
const int K = 24;
char tmp[10];
int main(){
    setIO("sample");
    while(~scanf("%d%d",&n,&m)){
        init();
        CLEAR(a);
        CLEAR(b);
        n++;
        root[1] = insert(0,K,root[0]);
         for(int i=2;i<=n;i++){
             scanf("%d",&a[i]);
             b[i] = b[i-1]^a[i];
             root[i] = insert(b[i],K,root[i-1]);
         } 
         while(m--){
             scanf("%s",tmp);
             if(tmp[0]=='A'){
                  n++;
                  scanf("%d",&a[n]);
                  b[n] = b[n-1]^a[n];
                  root[n] = insert(b[n],K,root[n-1]);
             }else{
                 int l,r,x;
                 scanf("%d%d%d",&l,&r,&x);
                 int ans = query(x^b[n],K,root[l-1],root[r]);
                 printf("%d\n",ans);
             }
         }
    }
    closeIO();
    return 0;
     
}

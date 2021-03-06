#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> _reserve_type_1;
typedef pair<int64,int64> pll;
#define pii _reserve_type_1
FILE * debug;
#define setIO _func_2_
void _func_2_(string file = "sample")
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}

void endline()
{
     ff(debug,"\n");
}

//for splay
#define L C[0]
#define R C[1]
#define F C[2]
//for fenwick tree
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LCH(_t),_l,mid
#define RIGHT RCH(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}
//for treap
template<class _type>
void zig(_type * & y)
{
  _type * x = y->lc;
  y->lc = x->rc;
  x->rc = y;
  y = x;
}

template<class _type>
void zag(_type * & y){
  _type * x = y->rc;
  y->rc = x->lc;
  x->lc = y;
  y = x;
}
#define ERROR_FILE_END -1
#define FILEOF(X) func_1_(X)
int func_1_(FILE * X)
{
 int cur = ftell(X);
 fseek(X,0L,SEEK_END);
 int ret  = ftell(X);
 fseek(X,cur,SEEK_SET);
 return ret;
}
class iomgr{
 FILE * A;
 char * rb, * endb;
 int fl;
public:
 void setting(FILE * _A){
	 A = _A;fl = 3*1024*1024;rb = new char[fl+3];fread(rb,1,fl,stdin);rb[fl] = -1;endb = rb+fl;
 }
 char exgetchar(){
	char ret = *rb; ++rb;
	return ret;
 }
 template <class T>
 void exread(T & x)
 {
  if(rb >= endb) return;
  char tmp = 0; T flag = 1,ret = 0;while(tmp != -1 && tmp != '-' && !isdigit(tmp)) tmp = exgetchar();
  if(tmp == -1) return;
  if(tmp == '-') flag = -1,tmp=exgetchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = exgetchar();
  x = flag *ret;
 }
 int64 exgetint()
 {
	int64 ret = ERROR_FILE_END;exread(ret);return ret;
 }
};
iomgr _global_reader_;
#undef setIO
void _func_3_(string file = "sample"){
 _func_2_(file);
 _global_reader_.setting(stdin);
}
#define setIO _func_3_
#undef gi
#define gi _global_reader_.exgetint()

#undef INF
#undef M
typedef long long ll;
#define MN 100010
const ll INF = (~0ULL>>2);
ll n;
ll d[MN],p[MN],u[MN],m[MN],c[MN];
pii a[MN];
ll delta,cost;
//part1 
ll fl1[MN*2];
void ins(ll pos,ll x){
 for(;pos <= n;pos += lb(pos)) fl1[pos] += x;
}
ll sum(ll pos){
 ll ret = 0;
 if(pos == 0) return 0;
 for(;pos;pos-=lb(pos)) ret += fl1[pos];
 return ret;
}
//part2 
struct _updw{
       ll mval,mpos;
       ll delta;
       _updw(ll _f = INF,ll _w = 0,ll _mpos = 0){
        mval = _f,delta = _w,mpos = _mpos;
       }
};
void operator >> (const _updw & a,_updw & b){b.delta += a.delta;}
void operator -- (_updw & a){a.mval+=a.delta;a.delta = 0;}
void operator ++ (_updw & a){a.mval = INF;a.mpos = 0;}
void operator << (_updw & a ,const _updw & b){ 
     if(b.mval + b.delta < a.mval){
      a.mval = b.mval+b.delta;
      a.mpos = b.mpos;
     }
}
_updw fl[MN*4],empty;
#define t1 ll t,ll l,ll r
#define M ll mid = ((l+r)>>1);
#define gol t<<1,l,mid
#define gor (t<<1)+1,mid+1,r
#define con 1,1,n
#define pd(x) fl[x]>>fl[x<<1];fl[x]>>fl[(x<<1)+1];--fl[x];
#define upd(x) ++fl[x];fl[x]<<fl[x<<1];fl[x]<<fl[(x<<1)+1];
_updw query(t1,ll _l,ll _r){
 if(_l > _r ) return empty;
 if(_l <= l && r <= _r){
  return _updw(fl[t].mval + fl[t].delta,0,fl[t].mpos);
 }
 _updw ret; 
 M;
 pd(t);
 if(_l <= mid)
  ret << query(gol,_l,_r);
 if(_r > mid)
  ret << query(gor,_l,_r);
 return ret;
}
void build(t1){
 if(l == r)
 {
  fl[t].mpos = l;
  return ; 
 }
 M;
 pd(t);build(gol);build(gor);upd(t);
 return;
}
void change(t1,ll _l,ll _r,ll delta){
 if(_l > _r ) return ;
 if(_l <= l && r <= _r){
 fl[t].delta += delta;
 return ;
 }
 M;
 pd(t);
 if(_l <= mid)
  change(gol,_l,_r,delta);
 if(_r > mid)
  change(gor,_l,_r,delta);
 upd(t);
 return;
}
void change(t1,ll pos,ll x){
   if(l == r){
    fl[t].mval = x;
    fl[t].delta = 0;
    return ;
   }
   M;
   pd(t);
   if(pos <= mid)
    change (gol,pos,x);
   else
    change (gor,pos,x);
   upd(t);
   return;
}
#undef pd
#undef upd
//part3
_updw ct[MN*4];
#define pd(x) ct[x]>>ct[x<<1];ct[x]>>ct[(x<<1)+1];--ct[x];
#define upd(x) ++ct[x];ct[x]<<ct[x<<1];ct[x]<<ct[(x<<1)+1];
void build1(t1){
 if(l== r){
  ct[t].mpos = l;
  ct[t].mval = 0;
  return  ;
 }
 M;
 pd(t);build1(gol);build1(gor);upd(t);
 return;
}
_updw query2(t1,ll _l,ll _r){
 if(_l > _r ) return empty;
 if(_l <= l && r <= _r){
  return _updw(ct[t].mval + ct[t].delta,0,ct[t].mpos);
 }
 _updw ret; 
 M;
 pd(t);
 if(_l <= mid)
  ret << query2(gol,_l,_r);
 if(_r > mid)
  ret << query2(gor,_l,_r);
 return ret;
}
void change2(t1,ll _l,ll _r,ll delta){
 if(_l > _r ) return ;
 if(_l <= l && r <= _r){
 ct[t].delta += delta;
 return ;
 }
 M;
 pd(t);
 if(_l <= mid)
  change2(gol,_l,_r,delta);
 if(_r > mid)
  change2(gor,_l,_r,delta);
 upd(t);
 return;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    build(con);
    build1(con);
    for(ll i = 1;i<=n;++i) d[i] = gi;
    for(ll i = 1;i<=n;++i) u[i] = gi;
    for(ll i = 1;i<=n;++i) p[i] = gi;
    for(ll i = 1;i<=n-1;++i) m[i] = gi;
    for(ll i = 1;i<=n-1;++i) c[i] = gi;
    for(ll i = 1;i<=n;++i) a[i] = MP(a[i-1].X+c[i-1],i);
    for(ll i = 1;i<=n;++i) a[i].X += p[i];
    sort(a+1,a+n+1);
    ll j = 1;
    for(ll i = 1;i<=n;delta -= c[i],++i){
     while(d[i] > 0)
     {
      ll forward = INF,backward = INF,cc=0;
      if(j <= n){
      while(j<= n && (a[j].Y <i || (u[a[j].Y] == 0)))
       ++j;
      if(j <= n)
      forward = a[j].X+delta;
      }
      _updw retval =  query2(con,1,i-1);
      backward = retval.mval;
      cc = retval.mpos;
      if(forward < backward){
        ll mcap = min(u[a[j].Y],d[i]);
        u[a[j].Y] -= mcap,d[i] -= mcap;
        cost += forward * mcap;
        ins(i,mcap);
        ins(a[j].Y,-mcap);
      }else{
       ll mcap = min(u[cc],d[i]);
       mcap = min(mcap,query(con,cc,i-1).mval);
       change(con,cc,i-1,-mcap);
       ll ncost = backward;
       u[cc] -= mcap,d[i] -= mcap;
       if(u[cc] == 0)  change2(con,cc,cc,INF);
       cost += ncost * mcap;
       while(true){
        retval = query(con,cc,i-1);
        if(retval.mval == 0)
        {
        ll k = retval.mpos;
        ll delta = c[k]+m[k];
        change(con,k,INF);
        change2(con,1,k,delta);     
        }
        else
         break;
       }
     }
    }
     ll dl = sum(i);
     if(dl > 0 )
      {
       change(con,i,dl);
       change2(con,1,i,-c[i]);
      }else{
       change(con,i,INF);
       change2(con,1,i,m[i]);
      }
      change2(con,i,i,p[i]);
    }
    printf(I64D,cost);
    closeIO();
    return EXIT_SUCCESS;
}

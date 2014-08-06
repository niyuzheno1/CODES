#include "mode.h"
#define MN 100086
#define MK 351
typedef long long ll;
const ll mod = 1000000007;
int n,m,p0;ll lmt;int sql;
int bsize,bnum;
struct point{
 int x,y,id;
 point(int X = 0,int Y = 0,int l = 0):
           x(X),y(Y),id(l){}
}a[MN];
inline ll dist (const point & a,const point & b){
 return sqr((ll)(a.x-b.x))+sqr((ll)(a.y-b.y));
}
vector<point> list[MK][MK];
int p[MN],w[MN],r[MN],sw[MN],v[MN];
void dfs(int c){
 if(v[c]) return;
 v[c] = 1;
 int lx = (a[c].x-sql)/bsize,rx = (a[c].x+sql)/bsize;
 int dy = (a[c].y-sql)/bsize,uy = (a[c].y+sql)/bsize;
 if(lx < 0) lx = 0; if(rx >= bnum) rx = bnum-1;
 if(dy < 0) dy = 0; if(uy >= bnum) uy = bnum-1;
 for(int i = lx;i<=rx;++i)
  for(int j = dy;j<=uy;++j){
   vector<point> & cv = list[i][j];
   for(vector<point>::iterator cp = cv.begin();cp != cv.end();++cp)
    if(dist(a[c],*cp) <= lmt && !v[cp->id])
     dfs(cp->id);
  }
}
inline bool tr(ll x){
 lmt = x;sql = sqrt(lmt)+1;
 CLEAR(v,0);
 dfs(p0);
 for(int i = 1;i<=m;++i)
  if(!v[p[i]]) return false;
 return true;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int Max = 0;
    scanf("%d%d%d",&n,&m,&p0);
    for(int i = 1;i<=n;++i)
    {
     scanf("%d%d",&a[i].x,&a[i].y);
     a[i].id = i;
     if(a[i].x>Max) Max = a[i].x;
    }
    if(Max<10000){
     bsize = 2000/sqrt(n)+1;
     bnum = 1000/bsize+1;
    }else{
     bsize = 200000/sqrt(n)+1;
     bnum = 100000/bsize+1;
    }
    for(int i = 1;i<=n;++i) list[a[i].x/bsize][a[i].y/bsize].pb(a[i]);
    for(int i = 1;i<=m;++i) scanf("%d%d%d",&p[i],&r[i],&w[i]);
    sw[0] = 0;
    for(int i = 1;i<=m;++i){
     w[i] = (w[i]+sw[r[i]])%mod;
     sw[i] = (sw[i-1]+w[i])%mod;
    }
    ll r = 0;
    while(!tr(r)) r += r+1ll;
    ll l = r/2ll;
    while(l < r){
     ll m = (l+r)>>1;
     if(tr(m)) r = m;else l = m+1;
    }
    printf("%d\n",(l%mod+(ll)sw[m])%mod);
    closeIO();
    return EXIT_SUCCESS;
}

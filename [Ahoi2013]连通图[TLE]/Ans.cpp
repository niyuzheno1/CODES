#include "mode.h"
#define MN 100010
#define MM 200010
#define MQ 100010
int n,m,q;
struct comm
{int n,a[4];}ask[MQ],back[MQ*30],*back_tail=back;
struct E{int x,y;}e[MM*30],*e_tail=e;
struct us
{
   int fa[MN];
   void init(int n){for(int i = 1;i<=n;++i) fa[i] = i;}
   int gf(int x){if(fa[x] == x) return x;return fa[x] = gf(fa[x]);}
   bool uni(int x,int y)
   {
   if(gf(x) == gf(y)) return 0;
   fa[gf(x)] = fa[gf(y)];return 1;
   }
}ufs;
bool ans[MQ] = {0};
int newV[MN],newE[MM];
void solve(int n,E * _e,int m,int l,int r)
{
     e_tail+=m;
     E*e = e_tail;
     copy(_e,e_tail,e);
     static bool b[MM]={0};for(int i = 0;i<m;++i) b[i] = 0;
     if(l == r)
     {
      for(int j = 0;j<ask[l].n;++j)b[ask[l].a[j]] = 1;
      ufs.init(n);
      int tot = 0;
      for(int i = 0;i<m;++i)
       if(!b[i])
        tot += ufs.uni(e[i].x,e[i].y);
      if(tot == n-1) ans[l]=1;
      e_tail-=m;
      return;
     }
     for(int i = l;i<=r;++i) for(int j = 0;j<ask[i].n;++j)b[ask[i].a[j]] = 1;
     ufs.init(n);
     for(int i = 0;i<m;++i)
      if(!b[i])
       ufs.uni(e[i].x,e[i].y);
     int n2 = 0;
     for(int i = 1;i<=n;++i)
      if(ufs.gf(i) == i)newV[i] = ++n2;
     for(int i = 1;i<=n;++i)
      if(ufs.gf(i)^i) newV[i]=newV[ufs.gf(i)];
     for(int i = 0;i<m;++i)
      e[i].x=newV[e[i].x],e[i].y = newV[e[i].y];
     int m2 = 0;
     for(int i = 0;i<m;++i) if(b[i]) newE[i] = m2++;
     for(int i = 0;i<m;++i) if(b[i]) e[newE[i]] = e[i];
     for(int i = l;i<=r;++i) 
      for(int j = 0;j<ask[i].n;++j)
       ask[i].a[j] = newE[ask[i].a[j]];
     {int m = (l+r)>>1,len=m-l+1;
     comm * back_head = back_tail;
     back_tail += len;
     copy(ask+1,ask+m+1,back_head);
     solve(n2,e,m2,l,m);
     copy(back_head,back_head+len,ask+l);
     back_tail -= len;
     solve(n2,e,m2,m+1,r);}
     e_tail -= m;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    for(int i = 0;i<m;++i) e[i].x=gi,e[i].y = gi;
    q = gi;
    for(int i = 0;i<q;++i)
    {
     ask[i].n = gi;
     for(int j = 0;j<ask[i].n;++j)
      ask[i].a[j]=gi-1;
    }
    solve(n,e,m,0,q-1);
    for(int i = 0;i<q;++i)
     puts(ans[i]?"Connected":"Disconnected");
    closeIO();
    return EXIT_SUCCESS;
}

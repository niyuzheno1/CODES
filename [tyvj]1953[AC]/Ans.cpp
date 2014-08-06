#include "mode.h"
#include "mathlab.h"
#define MN 30010
#define MM MN*2
#define MK (1 << 16) + 10
int tttt[6];
int n,st[MN],f[MN],g[MN],fa[MN],dep[MN],blk[MN],sz[MN],mx[MN];
cx A[MK],B[MK],C[MK];
struct _edge {
 int v,n,f;
};
_edge lk[MM];
#define tot tttt[0]
void add(int x,int y){
 lk[tot].v = y,lk[tot].n = st[x],st[x] = tot,++tot;
}
#undef tot
double ans;
int q[MN],r;
int findg(int x)
{
    r = 1;q[0] = x;fa[x] = -1;
    for(int i = 0;i<r;++i){
     int x = q[i];
     sz[x] = 1,mx[x] = -1;
     TRA(u,x){
      int y = lk[u].v;
      if(blk[y] || fa[x] == y) continue;
      q[r++] = y,fa[y] = x;
     }
    }
    for(int i = r-1;i>=0;--i){
     int x = q[i];
     if(fa[x] != -1){
      sz[fa[x]] += sz[x];
      mx[fa[x]] = max(mx[fa[x]],sz[x]);
     }
     mx[x] = max(mx[x],r-sz[x]);
    }
    int G = x;
    for(int i = 0;i<r;++i){
     int x = q[i];
     if(mx[x] < mx[G]) G =x;
    }
    stack<int> stk;
    while(!stk.empty()) stk.pop();
    dep[G] = 0,fa[G] = -1,r = 0;
    for(stk.push(G);!stk.empty();){
     int x = stk.top();stk.pop();q[r++] = x;
     TRA(u,x){
      int y= lk[u].v;
      if(blk[y] || fa[x] == y) continue;
      fa[y] = x,stk.push(y),dep[y] = dep[x] +1;
     }
    }
    return G;
}
void solve(int x){
  int G = findg(x);
  if(r == 1) return;
  for(int i = 0;i<r;++i) f[i] = 0;f[0] = 1;
  int l = 1;
  for(int i = 1;i<=r-1;++i){
    int x = q[i];
    if(fa[x] != G) continue;
    for(int j = i+1;j<=r-1;++j){
     int nowx = q[j];
     if(fa[nowx] == G) break;
     ++g[dep[nowx]],l = max(l,dep[nowx]);
    }
    int length = l<<1;
    ++g[1];
    int m;
    for(m = 1;m<(length<<1);m<<=1);
    for(int j = 0;j<m;++j) A[j] = B[j] = cx(0,0);
    for(int j = 0;j<length;++j) B[j].a = g[j],A[j].a = f[j];
    fft(A,m,1),fft(B,m,1);
    for(int j = 0;j<m;++j) C[j] = A[j]*B[j];
    fft(C,m,-1);
    for(int j = 1;j<=m-1;++j) 
     ans += (1.0/(j+1)) * ((int)(C[j].a/m+0.5));
    for(int j = 0;j<length;++j) f[j] += g[j];
    for(int j = i+1;j<=r-1;++j){
     int nowx = q[j];
     if(fa[nowx] == G) break;
     g[dep[nowx]] = 0;
    }
    g[1] = 0;
  }
  blk[G] = 1;
  TRA(u,G){
   int y = lk[u].v;
   if(blk[y]) continue;
   solve(y);
  }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&n);CLEAR(st,0xff);
    for(int i = 1;i<n;++i){
     int u,v;
     scanf("%d%d",&u,&v);
     add(u,v);add(v,u);
    }
    solve(0);
    ans = ans*2+n;
    printf("%.4f\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}

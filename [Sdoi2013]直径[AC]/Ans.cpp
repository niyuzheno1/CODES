#include "mode.h"
#define tra(x,y) for(int x=h[y];~x;x=nxt[x])
const int MN = 200010;
bool v[MN],e[MN],b[MN*2],mk[MN*2];
int rt,tot,r,q[MN],h[MN],p[MN*2],w[MN*2],nxt[MN*2];
int64 f[MN],g[MN];
inline void addedge(int x,int y,int z)
{
 p[tot] = y;w[tot] = z;mk[tot] = true;nxt[tot] = h[x];h[x] = tot++;
}
inline void bfs(int bg) {
 CLEAR(v,0);CLEAR(b,0);CLEAR(f,0);CLEAR(g,0);
 r = 0;
 v[q[r] = bg] = true; 
 for(int l = 0;l<=r;++l)
  tra(k,q[l])
   if(!v[p[k]] && mk[k]){
    v[p[k]] = true;
    b[k] = true;
    q[++r] = p[k];
   }
 for(int i = r;i>=0;--i){
  int x = q[i];
  tra(k,x)
   if(b[k]){
    int64 t = w[k]+f[p[k]];
    if(t > f[x]){
     g[x] = f[x];
     f[x] = t;
    }else if(t > g[x])
     g[x] = t;
   }
  if(f[x]+g[x]>f[rt]+g[rt])
   rt = x;
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,ans = 0;
    CLEAR(h,-1);
    for(int i = 1,x,y,z;i<n;++i)
    {
     x = gi,y = gi,z = gi*2;
     addedge(x,y,z);
     addedge(y,x,z);
    }
    bfs(1);
    printf(I64D,(f[rt]+g[rt])/2);printf("\n");
    for(int64 len1 = f[rt],len2 = g[rt];;){
     if(len1 <= len2)
      break;
     tra(k,rt)
      if(b[k] && w[k]+f[p[k]] == len1){
      len1 -= w[k];
      len2 += w[k];
      if(len1 < len2){
       int t = rt;
       rt = n+1;
       addedge(rt,t,(len1+len2)/2-len1);
       addedge(rt,p[k],(len1+len2)/2-len1);
       ans = -1;
       mk[k] = mk[k^1] = false;
      }
      else
       rt = p[k];
      break;
      }
    }
    bfs(rt);
    int c1 = 0,c2 = 0;
    tra(k,rt)
     if(b[k]){
      c1 += (w[k]+f[p[k]])==f[rt];
      c2 += (w[k]+f[p[k]])==g[rt];
     }
    if(f[rt] == g[rt]){
     if(c1 > 2){
      puts("0");
      return 0;
     }
     ans += 2;
     tra(k,rt)
     if(b[k] && w[k]+f[p[k]] == f[rt])
      e[p[k]] = true;
    }
    else{
     if(c1 ==  1){
      ++ ans;
      tra(k,rt)
       if(b[k] && w[k]+f[p[k]] == f[rt])
        e[p[k]] = true;
     }
     if(c2 ==  1){
      ++ ans;
      tra(k,rt)
       if(b[k] && w[k]+f[p[k]] == g[rt])
        e[p[k]] = true;
     }
    }
    for(int i = 0;i<=r;++i)
     if(e[q[i]]){
      int c = 0,x = q[i];
      tra(k,x)
       if(b[k] && w[k]+f[p[k]] == f[x])
        ++ c;
      if(c == 1){
       ++ ans ;
       tra(k,x)
       if(b[k] && w[k]+f[p[k]] == f[x])
        e[p[k]] = true;
      }
     }
    
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}

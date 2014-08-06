#include "mode.h"
#undef MP
#define MP 1500010
#define MN 500010
#define ME 2000010
#define MT 4000000
int n,Index = 1;
int p[MP],sz[MP],x[MN][3],q[MP],dep[MP];
int s[MP],hs[MN],id[MN],an[MN];
struct Edge{
 int y;
 Edge * next;
}*h[MN],mem[MN],*e=mem;
Edge*makeedge(int x,int y){
 e->y = y;e->next = h[x]; return e++;
}
void addedge(int x,int y){
 h[x] = makeedge(x,y);
}
void refresh(int t){
 s[t] = 0;
 for(int i = 0;i<3;++i) s[t]+=(x[t][i]>=n)?(s[x[t][i]]):(s[x[t][i]]>=2);
}
struct Node {
 int sz,cov;
 int R[3],v;
 void covIt(int k){
      v = k,cov = k;R[1]= R[2] = 0;if(k<3) R[k] = sz;
 }
 Node(){sz = cov = v = -1;}
}t;
Node operator +(Node & l,Node & r){
 if(l.sz == -1) {t = r;t.cov = -1;return t;}
 if(r.sz == -1) {t = l;t.cov = -1;return t;}
 t.sz = l.sz+r.sz;t.cov=-1;
 for(int i = 1;i<=2;++i) t.R[i] =(r.R[i]==r.sz)?(r.sz+l.R[i]):r.R[i];
 return t;
}
struct SegTree{
 int h;
 Node a[MT];
 void init(int n){
  for(h = 1;(1<<h)<n+2;++h);
  for(int i = 0;i<n;++i)
   a[i+(1<<h)+1].sz = 1;
  for(int i = (1<<h)-1;i>=0;--i) ref(i);
 }
 void relax(int x){
  int y = x<<1,z =y+1;
  if(a[x].cov != -1){
   if(a[y].sz!=-1)a[y].covIt(a[x].cov);
   if(a[z].sz!=-1)a[z].covIt(a[x].cov);
   a[x].cov = -1;
  }
 }
 void ref(int x){a[x]=a[x<<1]+a[(x<<1)+1];}
 void passdown(int x){
  for(int i = h-2;i>=0;--i)
   relax(x>>(i+1));
 }
 void upd(int x){
 for(x>>=1;x;x>>=1) ref(x);
 }
 void cover(int x,int y,int k){
  int l = x+(1<<h)-1,r = y+(1<<h)+1;
  passdown(l);passdown(r);
  while(l+1<r){
   if(!(l&1)) a[l^1].covIt(k);
   if((r&1)) a[r^1].covIt(k);
   l>>=1;r>>=1;
  }
  l = x+(1<<h)-1,r = y+(1<<h)+1;
  upd(l),upd(r);
 }
 void cover(int x,int k){
  x+=(1<<h);
  passdown(x);
  a[x].covIt(k);
  upd(x);
 }
 Node query(int x){
  x+=(1<<h);
  passdown(x);
  return a[x];
 }
 Node query(int l,int r){
  l += (1<<h)-1,r+=(1<<h)+1;
  passdown(l),passdown(r);
  Node L,R;L.sz = R.sz = -1;
  while(l+1<r){
   if(!(l&1)) L = L+a[l^1];
   if(r&1) R = a[r^1]+R;
   l>>=1;r>>=1;
  }
  return L+R;
 }
}T;
int stack[MP];
void dfs(int s){
 int r = 1;
 stack[0] = s;
 for(int i = 0;i<r;++i){
  int x = stack[i];
  id[x] = Index++;an[x] = s;
  if(hs[x] == -1) break;
  stack[r++]=hs[x];
 }
}
void modify(int x,int k){
 for(;x!=-1;){
  if(an[x] == x){
   Node tmp = T.query(id[x]);
   if(tmp.v == k){
    T.cover(id[x],3-k);
    x = p[x];
   }
   else {
   T.cover(id[x],(k==1)?(tmp.v+1):(tmp.v-1));
   break;
   }
  }else{
   int y = an[x];
   Node tmp = T.query(id[y],id[x]);
   if(tmp.sz == tmp.R[k]){
    T.cover(id[y],id[x],3-k);
    x = p[y];
   }
   else{
    y = id[x]-tmp.R[k];
    T.cover(y+1,id[x],3-k);
    tmp = T.query(y);
    T.cover(y,(k==1)?(tmp.v+1):(tmp.v-1));
    break;
   }
  }
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    T.init(n);
    for(int i = 0;i<n;++i)
     for(int j = 0;j<3;++j){
      x[i][j] = gi-1;
      p[x[i][j]] = i;
      if(x[i][j] >= n) ++sz[i];
      addedge(i,x[i][j]);
     }
    int r = 1;q[0]=0;
    for(int i = 0;i<r;++i)
    {
     int x = q[i];
     for(Edge* e = h[x];e;e=e->next){
      int y = e->y;
      if(y>=n)continue;
      q[r++] = y;
     }
    }
    p[0] = -1;
    for(int i = n;i<=3*n;++i) s[i] = gi;
    for(int i = n-1;i>=0;--i) refresh(q[i]);
    for(int i = 0;i<n;++i) hs[i] = -1;
    for(int i = r-1;i>=0;--i){
     int t = q[i];
     for(int j =0;j<3;++j) sz[t] += sz[x[t][j]];
     if(p[t] >=0){
      if(hs[p[t]] == -1 || sz[t] > sz[hs[p[t]]])
       hs[p[t]] = t; 
     }
    }
    for(int i = 0;i<=3*n;++i) id[i] = -1;
    for(int i = 0;i<n;++i){
     int x = q[i];
     if(id[x] != -1) continue;
     dfs(x);
    }
    
    for(int i = 0;i<n;++i)T.cover(id[i],s[i]);
    for(int q = gi;q--;){
     int x = gi-1;
     s[x] ^=1;
     modify(p[x],2-s[x]);
     printf("%d\n",T.query(id[0]).v>=2);
    }
    closeIO();
    return EXIT_SUCCESS;
}

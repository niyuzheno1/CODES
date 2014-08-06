#include "mode.h"
typedef long long ll;
#define MN 300001
#define MQ MN 
ll mod = 1000000007;
int n,q;
int p[MN],o[MN],id[MN],rb[MN];
ll ans[MN],dep[MN];
int st[MN],cur[MN],e=0;
struct edge{int v,n,f;};
edge lk[MN*2];
void add(int x,int y){
    lk[e].v = y,lk[e].n =st[x],st[x] = e,++e;
}
struct opr{
        int i,v,s;
        ll ans,x,k;
        opr(){ans = 0;}
}s[MQ],t[MQ];
void ref(ll & x){
 x = (x%mod+mod)%mod;
}
void work(int l,int r){
 if(l == r) return ;
 int m = (l+r)>>1;
 work(l,m),work(m+1,r);
 int n = l;
 int i = l,j = m+1;
 while(i<=m||j<=r){
  if(i<=m&& (j>r||id[s[j].v]>id[s[i].v]||id[s[j].v]==id[s[i].v] && s[i].s < s[j].s))
   t[n++] = s[i++];
  else
   t[n++] = s[j++];
 }
 int top = 0;
 ll k = 0,na = 0,ldep = 0;
 for(int i = l;i<=r;++i){
  s[i] = t[i];
  if(s[i].s == 1 && s[i].i > m) continue;
  if(s[i].s == 2 && s[i].i <= m) continue;
  while(top && rb[s[o[top]].v]<id[s[i].v]){
   int j = o[top];
   na -= s[j].x,k-=s[j].k;
   na += (ldep-dep[s[j].v])*s[j].k;
   ref(na);ref(k);
   --top;
  }
  na -= (dep[s[i].v]-ldep)*k;
  ref(na);
  if(s[i].s == 1){
      k+=s[i].k,na += s[i].x;
      ref(k),ref(na);
      o[++top] = i;
  }
  else{
       s[i].ans += na;
       ref(s[i].ans);
  }
  ldep = dep[s[i].v];
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    CLEAR(st,0xff);
    n = gi;
    for(int i = 1;i<=n-1;++i) p[i] = gi-1,add(p[i],i);
    q = gi;
    for(int i = 0;i<q;++i){
     s[i].s = gi;
     if(s[i].s == 1) s[i].v = gi-1,s[i].x =gi,s[i].k = gi;
     else s[i].v = gi-1;
     s[i].i = i;
    }
    int r = 0,Ind = 0;
    for(int i = 0;i<n;++i) cur[i] = st[i];
    o[0]=0,dep[0]=0,id[0]=++Ind;
    while(r>=0){
     while(r>=0 && cur[o[r]] == -1) rb[o[r]] = Ind,--r;
     if(r < 0) break;
     int x = o[r],y = lk[cur[x]].v;
     o[r+1]=y,cur[x]=lk[cur[x]].n;
     dep[y]=dep[x]+1,id[y] = ++Ind;
     ++r;
    }
    CLEAR(ans,0xff);
    work(0,q-1);
    for(int i  = 0;i<q;++i) if(s[i].s == 2) ans[s[i].i]=s[i].ans;
    for(int i = 0;i<q;++i)
     if(ans[i] != -1)
      printf("%d\n",ans[i]);    
    closeIO();
    return EXIT_SUCCESS;
}

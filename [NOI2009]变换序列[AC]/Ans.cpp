#include "mode.h"

const int MN =  20001,MM = MN *4 ;
struct edge{
       edge * next;
       int t;
}* V[MN],ES[MM];
int n,EC;
int S[MN][2],mat[MN];
bool vis[MN];
inline void addedge(int a,int b)
{
       ES[++EC].next = V[a];V[a] = ES+EC;V[a]->t = b;
}

void init()
{
     scanf("%d",&n);
     for(int i = 1,d,t1,t2;i<=n;++i)
     {
      scanf("%d",&d);
      t1 = i+d;
      if(t1 > n) t1 -= n;
      t2 = i-d; 
      if(t2 < 1) t2 += n;
      if(t1 < t2)
       S[i][0] = t1,S[i][1] = t2;
      else
       S[i][0] = t2,S[i][1] = t1;
      addedge(i,S[i][1]+=n);
      addedge(i,S[i][0]+=n);
     }
}
bool augment(int i)
{
 for(edge * e = V[i];e;e = e->next){
   int j = e->t;
   if(!vis[j]){
    vis[j] = 1;
    if(!mat[j] || augment(mat[j]))
    {
     mat[j] = i;
     mat[i] = j;
     return 1;
    }
   }
 }    
 return false;
}

void solve()
{
 int cnt = 0;
 for(int i = n;i>=1;--i)
 CLEAR(vis,0),augment(i) ? ++cnt : 0;
 if(cnt < n)
 {
  printf("No Answer\n");
  exit(0);
 }
}
void print()
{
 for(int i = 1;i<=n;++i,printf("%c",i==n+1?'\n':' '))
  printf("%d",mat[i]-n-1);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();solve();print();
    closeIO();
    return EXIT_SUCCESS;
}

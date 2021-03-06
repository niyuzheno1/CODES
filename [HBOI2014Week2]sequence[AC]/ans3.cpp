#include "mode.h"

#define MN 15010

int n,K,ans;
char str[MN];
int val[MN],fail[MN],ch[MN][30],nex[MN],tot,a[MN];

void ins(int & u,int v,int x)
{
     if(!ch[u][v]) ch[u][v]=++tot;
     nex[u] = ch[u][v],u = ch[u][v],val[u] = x;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    gets(str+1);
    n = strlen(str+1);K=gi;
    for(int i = 1;i<=n;++i)
    {
     CLEAR(val,0);CLEAR(fail,0);CLEAR(ch,0);CLEAR(a,0x7f);
     int u = 0;tot = 0;
     for(int j = i;j<=n+1;++j){
      ins(u,j==n+1?29:str[j]-'a',j);
     }
     queue<int> q;
     q.push(1);fail[1] = 0;
     while(!q.empty())
     {
      int x = q.front();q.pop();
      if(x == 5) 
      x = 5;
      for(int u = 0;u<=29;++u)
       if(ch[x][u])
       {
        int p = ch[x][u];
        int f = fail[x];
        if(u == 29) {
         fail[p] = nex[fail[x]];
         break;
        }
        while(f && !ch[f][u]) f = fail[f];
        if(ch[f][u]) fail[p] = ch[f][u];
        else  fail[p] = 0;
        q.push(ch[x][u]);
       }
      int d = 0;
      if(str[val[fail[x]]] == str[val[x]])
       d = nex[fail[x]];
      else
       d = 0;
      if(val[d]-i >= K)
       a[nex[x]] = min(val[d],a[d]);
      else
       a[nex[x]] = a[d];
      if(a[nex[x]]-i >= K && val[x]-(a[nex[x]]-i)>=a[nex[x]])
       ++ans;
     }
    }
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}

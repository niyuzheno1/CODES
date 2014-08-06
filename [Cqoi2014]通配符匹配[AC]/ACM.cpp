#include "mode.h"

#define _TRIE(x) t[x]

#define tra(i,x,y) for(int i = 0;i<=y;++i) if(_TRIE(x).n[i])

#define  MN  1010

#define  MX  27

char p[MN];

struct Trie{
  int n[MX+1];
  int fa,dval,last,word;
  set<int> val;
};

Trie t[MN];

int rt,n,to;

void ins(int & x,int y)
{
     if(!t[x].n[y])
      t[x].n[y] = ++to;
     t[t[x].n[y]].dval = y;
     x = t[x].n[y];
}
void show(int x)
{
     ff(debug,"here : %d fail : %d dval:%c word:%d last:%d ",x,t[x].fa,(x==1)?'0':(t[x].dval+'a'),t[x].word,t[x].last);
     int p = 0;
     tra(u,x,MX) ff(debug,"son#%d:%d",++p,t[x].n[u]);
     ff(debug,"\n");
     tra(u,x,MX) show(t[x].n[u]);
     
}

int main(int argc, char *argv[])
{
    rt = 1,to = 1;
    setIO("ACM");
    n = gi;
    for(int i = 1;i<=n;++i)
    {
     gets(p+1);
     int m = strlen(p+1);
     int u = rt;
     for(int j = 1;j<=m;++j)
      ins(u,p[j]-'a');
     t[u].word = 1;
    }
    
    queue<int> q;t[rt].fa = rt;
    tra(u,rt,MX) q.push(t[rt].n[u]),t[t[rt].n[u]].fa = rt;
    while(!q.empty())
    {
     int u = q.front();q.pop();
     if(u == 5) 
      u = 5;
     for(int i = 0;i<=MX;++i)
     {
      int v = t[u].fa;
      if(!t[u].n[i]) continue;
      while(v != 1 && !t[v].n[i]) v = t[v].fa;
      if(t[v].n[i]) t[t[u].n[i]].fa = t[v].n[i];
      else t[t[u].n[i]].fa = rt;
      q.push(t[u].n[i]);
      t[t[u].n[i]].last = t[t[t[u].n[i]].fa].word ? t[t[u].n[i]].fa : t[t[t[u].n[i]].fa].last ;
     }
    }
    show(rt);
    closeIO();
    return EXIT_SUCCESS;
}

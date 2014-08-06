#include "mode.h"

#define MN 100010
#define MX 29
typedef set<int> se;
typedef se::iterator si;
typedef vector<int> vi;
char a[MN];
int b[12][MN];
int n ,m , mct[12];
int cnt[12][MN];
int d[12],rt[12],last[MN],fail[MN],ch[MN][MX+1],tot,word[MN];
//se val[MN];
vi val[MN];
void ins(int & x,int y){
  if(!ch[x][y]) ch[x][y] = ++tot;
  x = ch[x][y];
}

void show(int x)
{
/*#ifndef RELEASE_VER

ff(debug,"here : %d fail:%d word: %d last:%d",x,fail[x],word[x],last[x]);
int t = 0;
ff(debug,"elements: ");
for(si i = val[x].begin();i != val[x].end();++i)
  ff(debug,"%d ",*i);
for(int i = 0;i<=MX;++i)
  if(ch[x][i]) ff(debug,"CH#%d : %d ",++t,ch[x][i]);
ff(debug,"\n");
for(int i = 0;i<=MX;++i)
 if(ch[x][i]) show(ch[x][i]);
#endif*/
}

int main(int argc, char *argv[])
{
    setIO("sample");
    gets(a+1);
    m = 1;
    n = strlen(a+1);
    int flag = (a[1]=='*'),flag2 = (a[n]=='*');
    for(int i = 1;i<=n;++i)
     if((a[i] == a[i-1] && a[i-1] == '*' )|| (a[i-1]==0 && a[i] == '*'))
      continue;
     else if(a[i] == '*')
     {++m;continue;}
     else
     {
         ++SIZE(b[m]);
         b[m][SIZE(b[m])] = a[i];
     }
    while(!SIZE(b[m]) && m > 0) --m;
    /*for(int i = 1;i<=m;ff(debug,"\n"),++i)
     for(int j = 1;j<=SIZE(b[i]);++j)
      ff(debug,"%c",char(b[i][j]));*/
    //build AC-M
    for(int i = 1;i<=m;++i) rt[i] = ++tot;
    for(int i = 1;i<=m;++i){
     int v = rt[i];
     int p = SIZE(b[i]);
     for(int j = 1;j<=p;++j){
      if(b[i][j] == '?' && b[i][j-1] != '?' &&j-1!=0)
       ++mct[i],word[v] = 1,val[v].pb(j-1);
      if(b[i][j] == '?')
       v = rt[i];
      else
       ins(v,b[i][j]-'a');
     }
     if(b[i][p] != '?')
      ++mct[i],word[v] = 1,val[v].pb(p);
     v = rt[i];//ff(debug,"%d\n",v);
     queue<int> q;fail[v] = v;
     for(int j = 0;j<=MX;++j) if(ch[v][j])  q.push(ch[v][j]),fail[ch[v][j]] = v;
     while(!q.empty())
     {
      int u = q.front();q.pop();
      for(int j= 0;j<=MX;++j){
       int v = fail[u],cl = ch[u][j];;
       if(!cl) continue;
       while(v != rt[i] && !ch[v][j]) v = fail[v];
       if(ch[v][j]) fail[cl] = ch[v][j];
       else fail[cl] = rt[i];
       
       if(word[fail[cl]]) //case 1
        last[cl] = fail[cl];
       else // other case
        last[cl] = last[fail[cl]];
       // updata
       /*for(si k = val[last[cl]].begin();k != val[last[cl]].end();++k)
        val[cl].insert(*k);*/
       q.push(cl);
      }
     }
     show(rt[i]);
    }
    
    //done
    n=gi;
    for(int i = 1;i<=n;++i)
    {
     CLEAR(cnt,0),CLEAR(d,0x7f);d[0] = 0;
     if(i == 6) 
      i = 6;
     gets(a+1);
     int k = strlen(a+1);
     //run AC-M
     for(int j = 1;j<=m;++j){
     int u = rt[j];
      if(j == 2)
       j = 2;
      for(int i = 1;i<=k;++i)
      {
       if( i == 48)
        i = 48;
       int p = a[i]-'a';
       while(u != rt[j] && !ch[u][p]) u = fail[u];
       if(ch[u][p]) u = ch[u][p];
       for(int pp = u;pp != rt[j] && pp != 0;pp=last[pp])
        for(int tt = 0;tt<val[pp].size();++tt)
        if(i-val[pp][tt]+1 > 0 )
         ++cnt[j][i-val[pp][tt]+1];
      }
     }
     //done
     for(int j = 1;j<=m;++j)
      for(int i = 1;i<=k;++i)
       if(cnt[j][i] == mct[j] )
        if(i+SIZE(b[j])-1 <= k)
         if( d[j]>=INF && i > d[j-1]+b[j-1][0]-1)
        d[j] = i;
     if(d[m] < INF && ((d[1] == 1||flag)) &&(d[m]+b[m][0]-1==k||flag2)) puts("YES");
     else puts("NO"); 
    }
    closeIO();
    return EXIT_SUCCESS;
}

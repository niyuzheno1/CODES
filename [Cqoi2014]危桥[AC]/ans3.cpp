#include "mode.h"

#undef INF
#define MN 101
#define INF 0x7f7f7f7f
int q[MN],f[MN],map[MN][MN],temp[MN][MN];
int n,s1,e1,s2,e2,q1,q2,flow,tt,flag;
char c,enter;
int bfs()
{
     CLEAR(q,0);CLEAR(f,0xff);
     int h = 0,t = 1;f[0] = 1;
     while(h < t)
     {
      int now = q[++h];if(now == n) return 1;
      for(int i = 0;i<=n;++i)
       if(map[now][i] && f[i] == -1)
       {
        q[++t] = i;
        f[i] = f[now]+1;
       }
     }     
     return 0;
}
int dinic(int sta,int sum)
{
    if(sta == n) return sum;
    int os = sum;
    for(int i = 0;i<=n;++i)
     if(map[sta][i] && f[i] == f[sta]+1)
     {
      int Min = dinic(i,min(os,map[sta][i]));
      map[sta][i] -= Min;map[i][sta] += Min;os-=Min;
     }
    if(os == sum) f[sta] =-1;
    return sum-os;
}

int main()
{
    setIO("sample");
    while(~scanf("%d%d%d%d%d%d%d",&n,&s1,&e1,&q1,&s2,&e2,&q2))
    {
     ++s1,++e1,++s2,++e2;
     CLEAR(map,0);CLEAR(temp,0);
     for(int i = 1;i<=n;++i)
     {
     enter = getchar();
      for(int j = 1;j<=n;++j)
      {
       c = getchar();
       if(c == 'O')
        map[i][j] = temp[i][j] = 2;
       if(c == 'N')
        map[i][j] = temp[i][j] = INF;
      }
     }
     flag = 1;
     flow = 0;map[0][s1] = q1*2;map[0][s2] = q2*2;
     map[e1][++n] = q1*2;map[e2][n] = q2*2;
     while(bfs()){
      tt = dinic(0,INF);
      flow += tt;
      }
     if(flow < 2*(q1+q2)) flag =0;
     if(flag){
      CLEAR(map,0);
      for(int i = 1;i<n;++i)
       for(int j = 1;j<n;++j)
        map[i][j] = temp[i][j];
      map[0][s1] = q1*2;map[0][e2] = q2*2;map[e1][n] = q1*2;map[s2][n] = q2*2;flow = 0;
      while(bfs()){
      tt = dinic(0,INF);
      flow += tt;
      }
      if (flow<2*(q1+q2)) flag=0; 
     }
     if(flag) puts("Yes");else puts("No");
    }
    closeIO();
}

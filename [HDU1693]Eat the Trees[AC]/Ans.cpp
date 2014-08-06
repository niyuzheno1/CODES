#include "mode.h"
#define MS 1000010
#define MH 10007
#include "hash.h"
#define MD 15
int n,m;
int code[MD],maze[MD][MD];
hash hm[2];
void decode(int * code,int m,int st)
{
     int i;
     for(int i=m;i>=0;st>>=1,--i) code[i] = st&1;
}

int encode(int * code,int m)
{
     int st = 0;
     for(int i = 0;i<=m;++i)
      st<<=1,st |= code[i];
     return st;
}
void init()
{
     n = gi;m=gi;
     for(int i = 1;i<=n;++i) for(int j = 1;j<=m;++j) maze[i][j] = gi;
     for(int i = 1;i<=n;++i) maze[i][m+1]=0;
     for(int i = 1;i<=m;++i) maze[n+1][i]=0;
}

void shift(int * code,int m)
{
 for(int i = m;i>=0;--i) code[i] = code[i-1];
 code[0] = 0;
}

void case1(int i,int j,int cur)
{
     int left,up;
     for(int k = 0;k<hm[cur].size;++k)
     {
      decode(code,m,hm[cur].state[k]);
      left = code[j-1];
      up = code[j];
      if(left && up)
      {
       code[j-1]=code[j] = 0;
       if(j == m)shift(code,m);
       hm[cur^1].push(encode(code,m),hm[cur].f[k]);
      }
      else if(left || up )
      {
           if(maze[i][j+1])
           {
            code[j-1] = 0,code[j] = 1;
            hm[cur^1].push(encode(code,m),hm[cur].f[k]);
           }
           if(maze[i+1][j])
           {
            code[j-1] = 1,code[j] = 0;
            if(j == m) shift(code,m);
            hm[cur^1].push(encode(code,m),hm[cur].f[k]);
           }
      }
      else
      {
       if(maze[i][j+1] && maze[i+1][j])
       {
        code[j]=code[j-1]=1;
        hm[cur^1].push(encode(code,m),hm[cur].f[k]);
       }
      }
     }
}

void case2(int i,int j,int cur)
{
     for(int k=0;k<hm[cur].size;++k)
     {
      decode(code,m,hm[cur].state[k]);
      code[j-1] = code[j] = 0;
      if(j == m) shift(code,m);
      hm[cur^1].push(encode(code,m),hm[cur].f[k]);
     }
}

void solve()
{
     int cur = 0;
     long long ans = 0;
     hm[cur].init();hm[cur].push(0,1);
     for(int i = 1;i<=n;++i)
      for(int j = 1;j<=m;++j)
      {
              hm[cur^1].init();
              if(maze[i][j]) case1(i,j,cur);
              else case2(i,j,cur);
              cur^=1;
      }
     for(int i = 0;i<hm[cur].size;++i)
      ans += hm[cur].f[i];
     printf("There are %I64d ways to eat the trees.\n",ans);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int T=gi;
    int iCase = 0;
    while(T--)
    {
    ++iCase;
    printf("Case %d: ",iCase);
    init();
    solve();
    }
    closeIO();
    return EXIT_SUCCESS;
}

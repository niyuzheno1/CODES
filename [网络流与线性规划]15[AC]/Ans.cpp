#include "mode.h"
#undef INF
#define INF 0x7f7f7f7f
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};
#define MN 110
#define MK 11
int tttt[4];
int n,k,a,b,c,bk;
int mp[MN][MN][MK];
int st[MN*MN*MK];
struct _edge{
 int n,v,w,f;
};
_edge lk[MN*MN*MK*5];
int d[MN*MN*MK];
#define tot tttt[0]
void init(){CLEAR(st,0xff);tot = 1;}
void add(int x,int y,int z){
++tot;lk[tot].v = y;lk[tot].n =st[x];lk[tot].w = z;st[x] = tot;
}
#undef tot
bool range(int x,int y){
 return x>=1 && x <=n && y >= 1 && y <= n;
}
int main(int argc, char *argv[])
{
    setIO("sample");init();
    scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
    #define tot tttt[1]
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      for(int l = 0;l<=k;++l)
       mp[i][j][l] = ++tot;
    #undef tot
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
     {
      int x;
      scanf("%d",&x);
      int cot = 0;
      if(x == 0)
       cot = c;
      for(int w = 0;w<k;++w)
       add(mp[i][j][w],mp[i][j][k],cot+a);
      if(!x){
       for(int d = 1;d<=4;++d){
        int nx = i+dx[d];
        int ny = j+dy[d];
        cot = 0;
        if(!range(nx,ny)) continue;
        if(dx[d] < 0 || dy[d] < 0)
         cot = b;
        for(int w = 1;w<=k;++w)
         add(mp[i][j][w],mp[nx][ny][w-1],cot);
       }
      }else{
        for(int d = 1;d<=4;++d){
        int nx = i+dx[d];
        int ny = j+dy[d];
        cot = 0;
        if(!range(nx,ny)) continue;
        if(dx[d] < 0 || dy[d] < 0)
         cot = b;
        add(mp[i][j][k],mp[nx][ny][k-1],cot);
        }
      }
     }
    CLEAR(d,0x7f);
    d[mp[1][1][k]] = 0;
    queue<int> q;
    q.push(mp[1][1][k]);
    while(!q.empty()){
      int x = q.front();q.pop();
      if(x >= 73 && x <= 76)
       bk = 1;
      TRA(i,x)
       if(d[lk[i].v] > d[x]+lk[i].w){
       d[lk[i].v] = d[x]+lk[i].w;
       q.push(lk[i].v);
       }
    }
    int ans = INF;
    for(int i = 0;i<=k;++i)
     ans = min(ans,d[mp[n][n][i]]);
    printf("%d",ans);
    closeIO();
    return EXIT_SUCCESS;
}

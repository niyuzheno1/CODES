#include "mode.h"
typedef double ld;
const int MN = 1010,MM = 11;
typedef pair<pii,int> piii;
typedef map<piii,ld> nmap;
typedef nmap::iterator itor;
nmap f[2];
ld a[MN][MM];
int n,m;
int main(int argc, char *argv[])
{
    setIO("sample");
    for(int i = 0;i<2;++i) f[i].clear();
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j)
      scanf("%lf",&a[i][j]);
    f[0][MP(MP(0,0),1)] = 1;
    for(int i = 1;i<=n;++i)
    {
     int now = i&1,last = now^1;
     f[now].clear();
     for(itor it = f[last].begin();it != f[last].end();++it)
     {
      int col = (*it).X.X.X,len = (*it).X.X.Y,len1 = (*it).X.Y;
      double pp = (*it).Y;
      for(int j = 1;j<=m;++j)
      {
       if(j != col)
       f[now][MP(MP(j,1),len1)] += pp*a[i][j];
       else
       f[now][MP(MP(j,len+1),max(len1,len+1))] += pp*a[i][j];
      }
     }
    }
    double ans = 0;
    int ECase = 0;
    for(itor it = f[(n)&1].begin();it != f[(n)&1].end();++it)
    {
     //++ECase;
     //ff(debug,"number %d : col:%d len:%d len1:%d P:%.5f\n",ECase,(*it).X.X.X,(*it).X.X.Y,(*it).X.Y,(*it).Y);
     ans += (*it).Y*double((*it).X.Y);
    }
    printf("%.6f\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}

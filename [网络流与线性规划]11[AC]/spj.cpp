#include "mode.h"
#include "spj.h"
#define MN 110
int mp[MN][MN],n,m,v;
int vis[MN];
/*A :in
  B :ans
  C :out
  D :res
*/
typedef map<string,int> msi;
msi rd;
int main()
{
    setspj();
    fr(A,"%d%d",&n,&v);
    for(int i = 1;i<=n;++i)
    {
      char buf[110];
      fr(A,"%s",buf);
      string  p =buf;
      rd[p] = i;
    }
    for(int i = 1;i<=v;++i)
    {
     char buf[110];
     fr(A,"%s",buf);string  p =buf;
     int x,y;x = rd[p];
     fr(A,"%s",buf);p =buf;
     y = rd[p];
     mp[x][y] = mp[y][x] = 1;
    }
    fr(C,"%d",&m);++m;
    int last = 0;
    for(int i = 1;i<=m;++i) 
     {
      char buf[110];
      fr(C,"%s",buf);
      string  p =buf;
      if(last != 0 && !mp[last][rd[p]])
       return 1; 
     }
    for(int i = 1;i<=n;++i)
     if(vis[i] > 2 || (vis[i] == 2 && i != 1))
      return 1;
    closespj();
    return 0;
}

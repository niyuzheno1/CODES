#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#define X first
#define Y second
#define MP make_pair
#define rep(o,x) for(int o = 1;o<=x;o++)
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
int n,m,S;
const int MAXN = 30100;
const int MAXM = 210;
const int mod = 79;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);
 #endif
}
char s[MAXM];
LL pre[MAXN][MAXM],nex[MAXN][MAXM];
pii v[MAXN];
int main(int argc, char *argv[])
{
    setIO("penguin");
    scanf("%d%d%d",&n,&m,&S);
    for(int i = 1;i<=n;i++)
    {
     scanf("%s",&s[1]);
     for(int j = 1;j<=m;j++)
      pre[i][j] = pre[i][j-1]*mod+(s[j]-'a');
     for(int j = m;j>=1;j--)
      nex[i][j] = nex[i][j+1]*mod+(s[j]-'a');
    }
    int ans = 0;
    for(int i = 1;i<=m;i++)
    {
     for(int j = 1;j<=n;j++)
      v[j] = MP(pre[j][i-1],nex[j][i+1]);
     sort(v+1,v+1+n);
     int cnt = 0;
     for(int j = 1;j<=n;j++){
      cnt++;
      if(j==n||v[j+1].X != v[j].X|| v[j+1].Y != v[j].Y)
      {
       ans += (cnt*(cnt-1))/2;
       cnt = 0;
      }
     }
    }
    printf("%d\n",ans);
    closeIO();   
    return EXIT_SUCCESS;
}

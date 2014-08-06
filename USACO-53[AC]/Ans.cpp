#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string ta[30010];
int f[30010];
int ans;
int n;
struct note
{
 int term;
 int p[27];
};
note r[3000010];
int tot;
void in(char x[],int y)
{
 int t = 1;
 for(int i = 0;i<strlen(x);i++){
  if(r[t].p[x[i]-'a'] == 0)
   tot++,r[t].p[x[i]-'a'] = tot;
  t = r[t].p[x[i]-'a'];
  }
 r[t].term = y;
}
char p[3000010];
int mp[27][27];
bool visit[27];
bool dfs2(int x)
{
     if(visit[x])
      return false;
     visit[x] = 1;
	 int ans = 1;
     for(int i = 0;i<='z'-'a';i++)
      if(mp[x][i])
       ans = ans&&dfs2(i);
	 visit[x] = 0;
     return ans;
}
bool check()
{
     for(int i = 0;i<='z'-'a';i++){
      memset(visit,0,sizeof(visit));
      if(!dfs2(i))
       return false;
      }
     return true;
}
void dfs(int x)
{
     if(r[x].term)
     {
      
      if(check())
       f[r[x].term] = 1,ans++;
      return;
     }
     for(int i = 0;i<='z'-'a';i++)
      if(r[x].p[i] != 0){
       
       for(int j = 0;j<='z'-'a';j++)
        if(r[x].p[j] != 0 && j != i)
         mp[i][j]++;
       dfs(r[x].p[i]);
       for(int j = 0;j<='z'-'a';j++)
        if(r[x].p[j] != 0 && j != i)
         mp[i][j]--;
      }
}
int main(int argc, char *argv[])
{
    freopen("first.in","r",stdin);
    freopen("first.out","w",stdout);
    scanf("%d",&n);
    tot  = 1;
    for(int i = 1;i<=n;i++){
     scanf("%s",&p),in(p,i);
     ta[i] = p;
    }
    memset(p,0,sizeof(p));
    dfs(1);
    printf("%d\n",ans);
    for(int i = 1;i<=n;i++)
     if(f[i] == 1)
      printf("%s\n",ta[i].c_str());
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}

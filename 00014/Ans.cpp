#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
int a[60][2];
long long ma;
int tot;
int set[20000][60];
int map[60];
long long ans = 0;
void dfs(int x)
{
  if(x>n){
   for(int i = 1;i<=tot;i++)
   {
    bool flag = true;
    for(int j = 1;j<=n;j++)
     if(set[i][j] != map[j]){
      flag = false;
      break;
     }
    if(flag)
     return;
   }
   long long y = ma;
   for(int i = 1;i<=n;i++)
    if(map[i] > 0)
     y = y/map[i];
   ans = (ans%1000000007+ y%1000000007)%1000000007;
   tot++;
   for(int j = 1;j<=n;j++)
    set[tot][j] = map[j];
   return;
  }
  
  for(int i = 0;i<=1;i++)
  {
  
  
   map[a[x][i]]++;
   dfs(x+1);
   map[a[x][i]]--;
  }
 
  return;
}
int main()
{
    
    ma = 1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%d",&a[i][0]);
     ma = i*ma;
    }
    ma %= 1000000007;
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i][1]);
    dfs(1);
    printf("%lld",ans%1000000007);
    system("PAUSE");
	return 0 ;
}
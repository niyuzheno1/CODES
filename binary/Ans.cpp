#include <cstdlib>
#include <iostream>
#include <cstring>
#define read(m) scanf("%I64d",&m)
using namespace std;
typedef long long int64;
const int64 inf = 0x7f7f7f7f;
 int64 in64 ;
int64 f[40][40][40][40][2];
int64 nA,nB,nC,n;
char tmp[100];
void get(int64 & a,int64 & b,int64 c)
{
    itoa(int(c),tmp,2);
    b = max(size_t(b),strlen(tmp));
    for(int i = 0;i<strlen(tmp);i++)
     if(tmp[i] == '1')
      a++;
}
int64 dfs(int64 x,int64 a,int64 b,int64 c,int64 p)
{
 if(x == 0)
 {
   if(a == 0 && b == 0 && c == 0 && p == 0)
    return 0;
   return inf;
 }
 int64 & ans = f[x][a][b][c][p];
 if(ans < in64)
  return ans;
 if(p == 0)
 {
   ans = min(ans,dfs(x-1,a,b,c,0));
   ans = min(ans,dfs(x-1,a,b,c-1,1)+int64(int64(1)<<(x-1)));
   ans = min(ans,dfs(x-1,a,b-1,c-1,0)+int64(int64(1)<<(x-1)));
   ans = min(ans,dfs(x-1,a-1,b,c-1,0)+int64(int64(1)<<(x-1)));
 }
 else
 {
   ans = min(ans,dfs(x-1,a-1,b-1,c,0));
   ans = min(ans,dfs(x-1,a-1,b-1,c-1,1)+int64(int64(1)<<(x-1)));
   ans = min(ans,dfs(x-1,a-1,b,c,1));
   ans = min(ans,dfs(x-1,a,b-1,c,1));
 }
 return ans;
  
}
int main(int argc, char *argv[])
{
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    scanf("%I64d",&n);
    for(int i = 1;i<=n;i++){
    memset(f,0x7f,sizeof(f));
    in64 = f[0][0][0][0][0];
    int64 A,B,C,m;
    m = 0;
    nA = nB = nC = 0;
    scanf("%I64d%I64d%I64d",&A,&B,&C);
    get(nA,m,A);get(nB,m,B);get(nC,m,C);
    int64 getcd = dfs(m,nA,nB,nC,0);
    if(getcd >= inf)
     printf("-1\n");
    else
    printf("%I64d\n",getcd);
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}

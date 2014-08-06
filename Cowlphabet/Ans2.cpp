#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxr = 256;
int U,L,P;
char str[10];
bool rela[maxr][maxr];
int f[maxr][maxr][maxr];
int dfs(char alpha,int U1 ,int L1)
{
  if(f[alpha][U1][L1] != -1)
	return f[alpha][U1][L1];
  if(U1 == U && L1 == L)
	return (f[alpha][U1][L1]=1);
  f[alpha][U1][L1] = 0;
  for(char c = 'a';c <= 'z';c++)
	if(L1 < L)
		f[alpha][U1][L1]+=dfs(c,U1,L1+1);
  
  for(char c = 'A';c <= 'Z';c++)
	if(U1 < U)
		f[alpha][U1][L1]+=dfs(c,U1+1,L1);
  return f[alpha][U1][L1];
}
bool run[maxr];
int main()
{
 scanf("%d%d%d",&U,&L,&P);
 for(int i = 1;i<= P;i++)
 {
	scanf("%s",&str);
	rela[str[0]][str[1]] = 1;
	run[str[0]] = 1;
 }
 int ans = 0;
 for(char c = 'a';c <= 'z';c++)
	if(run[c])
		ans+=dfs(c,0,1);
 for(char c = 'A';c <= 'Z';c++)
	if(run[c])
		ans+=dfs(c,1,0);
 printf("%d",ans);
 return 0;
}

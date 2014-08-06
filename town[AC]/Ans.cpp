#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int md = 110,mh = 2097152,cz = 7;
const int cb[] = {0,2,3,4,5,0};
int n,d,f[md][mh],hash[cz][mh];
int sc[cz][mh];
char str[md];
int S;
int h(int y,int x)
{
  if(x == 72)
   x = 72;
  int u[10] = {0},c = 0;
  if(x == 0)
	   return 0;
  for(int i = x;i>0;i>>=3){
	   if((i & ((1<<3)-1))>5)
		   return -1;
     u[c] = ((i & ((1<<3)-1))),c++;
   }
   if(u[y] == 0)
	    return -1;
   bool f = true;
   while(f){
	f= false;
   for(int i = 1;i<=n;i++)
	if(u[i] != 0){
	  int a = 1,b = u[i];
     for(int j = i+1;j<=n+1;j++,a++)
		 if(u[i] != u[j])
		 {
		   if(a == 1)
			   break;
		   f = 1;
		  sc[y][x] += a*(1<<b);
		  for(int k = i;k<j;k++)
			   u[k] = 0;
		  u[y] = cb[b];
		  break;
		 }
     }
    }
    int ret = 0;
	for(int i = n;i>=0;i--)
	{
		ret<<=3;
		ret = (ret|u[i]);
	}
	return ret;
}
void init()
{
	for(int j = 1;j<=n;j++)
	 for(int i = 0;i<S;i++)
	  hash[j][i] = h(j,i);
	/*for(int j = 1;j<=n;j++){
	   for(int i = 0;i<S;i++)
		 printf("f[%d][%d] = %d ",j,i,hash[j][i]);
	   printf("\n");
    }*/
}
void dp()
{
     str[d] = '0';
     for(int x = 0;x<=d;x++)
      for(int y = 0;y<S;y++)
       if(f[x][y] != -1)
       {
        for(int i = 1;i<=n;i++)
         if(((y>>(3*i))&((1<<3)-1)) == 0)
         {
          int u = (y|((str[x]-'0')<<(3*i)));
          if(sc[i][u] != 0)
           sc[i][u] = sc[i][u];
          f[x+1][hash[i][u]] =max(f[x][y]+sc[i][u],f[x+1][hash[i][u]]);
         }
         if((y &((1<<3)-1)) != 0)
         {
          int xx = (y &((1<<3)-1));
          int u = y ^xx;
          {
           int k = 1;
           for( k = 1;k<=n;k++)
           if(((u>>(3*k))&((1<<3)-1)) == 0){
           int v = (u|((xx)<<(3*k)));
           v = (v|(str[x]-'0'));
           if(sc[k][v] != 0)
            sc[k][v] = sc[k][v];
           f[x+1][hash[k][v]] = max(f[x][y] + sc[k][v],f[x+1][hash[k][v]]);
           }
          }
         }
          else
          {
           int xx = (y|(str[x]-'0'));
           f[x+1][xx] = max(f[x+1][xx],f[x][y]);
          }
         
       }
      
}
void solve()
{
     int ans = 0;
     for(int x = 0;x<=d+1;x++)
      for(int y = 0;y<S;y++)
       if(f[x][y] > ans)
        ans = f[x][y];
     printf("%d\n",ans);
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout); 
	memset(f,0xff,sizeof(f));
	scanf("%d%d",&n,&d);
	S = 1<<(3*(n+1));
	scanf("%s",str);
	f[0][0] = 0;
	init();
	dp();
    solve();
	fclose(stdin);fclose(stdout);
	return 0;
}

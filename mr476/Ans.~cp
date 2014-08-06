#include <map>
#include <string>
#include <queue>
#define zero(x) memset(x,0,sizeof(x))
using namespace std;

const string m = "01356789ACEF";
const int qx[] = 
{
 0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15
};
const int f[30][30]=
{
 {4,0,1,4,5},
 {2,1,2},
 {4,2,3,6,7},
 {7,1,4,5,6,7,9,13},
 {7,2,4,5,6,7,10,14},
 {2,7,11},
 {2,4,8},
 {7,1,5,8,9,10,11,13},
 {7,2,6,8,9,10,11,14},
 {4,8,9,12,13},
 {2,13,14},
 {4,10,11,14,15}
};
map<int,string> ans;
map<int,int> s;
int totwo(string x)
{
 int m = 0;
 for(int i = 3;i>=0;i--)
 {
  m *= 16;
  if(x[i] <= '9' && x[i] >= '0')
   m+=qx[x[i]-'0'];
  else
   m+=qx[x[i]-'A'+10];
 }
 return m;
}
int c(int x,int y)
{
 for(int i = 1;i<=f[y][0];i++)
  x ^= (1<<f[y][i]);
 return x;
}
char h[10];
char inf[101],ouf[101];
int main(int argc, char *argv[])
{

    int x = totwo("0660");
    queue<int> q;
    q.push(x);
    s[x] = 1;
	ans[x] = "";
	x = c(x,8);
	x = c(x,9);
	x = c(x,10);
	x = c(x,11);
	
    while(!q.empty())
    {
    int y = q.front();q.pop();
    
     for(int j = 0;j<=11;j++)
     {
      int k = c(y,j);
      if(!s[k])
      {
       s[k] = 1;
       q.push(k);
       ans[k] = ans[y]+m[j];
      }
     }
    }
 for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr476.in%d",cani);
    sprintf(ouf,"mr476.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     scanf("%s",h);
     string lx = h;
     x = totwo(lx);
     printf("%s\n",ans[x].c_str());
    }
     fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}

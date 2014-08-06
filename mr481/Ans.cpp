#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define X first
#define Y second
#define sqr(x) (x)*(x)
#define zero(a) memset(a,0,sizeof(a))

using namespace std;

typedef pair<int,int> o;
typedef pair<double,o> b;
int M,N;
int m[510];
int h[1010];
double p[1010][2];
double ans = 0;
vector<b> l;
int t(int x)
{
    if(h[x] == x)
     return x;
    else
     return (h[x] = t(h[x]));
}
void r(int x,int y)
{
     h[t(x)] = t(y);
}
char inf[101],ouf[101];
int up(double x)
{
	double y = 0;
	y = int(x);
	if(x-y > 0)
		return int(y+1);
	else
		return int(y);
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr481.in%d",cani);
    sprintf(ouf,"mr481.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	M = N = 0;
	zero(m);
	zero(h);
	zero(p);
	ans = 0;
	l.clear();
    scanf("%d",&M);
    for(int i = 1;i<=M;i++)
     scanf("%d",&m[i]);
    
    sort(m+1,m+M+1);
    
    scanf("%d",&N);
    for(int i = 1;i<=N;i++){
		int x,y;
     scanf("%d%d",&x,&y),h[i]=i;
		p[i][0] = x;
		p[i][1] = y;
	}
    for(int i = 1;i<=N;i++)
     for(int j = i+1;j<=N;j++)
      l.push_back(b(sqrt(sqr(p[i][1]-p[j][1])+sqr(p[i][0]-p[j][0])),o(i,j)));
    sort(l.begin(),l.end());
    for(int i = 0;i<l.size();i++)
     if(t(l[i].Y.X) != t(l[i].Y.Y))
     {
	 
      r(l[i].Y.X,l[i].Y.Y);
      ans = max(ans,l[i].X);
     }
   
	int ans2 = 0,h = 0;
	h = up(ans);
	 for(int i = 1;i<=M;i++)
		 if(m[i] >= h)
			 ans2++;
	printf("%d\n",ans2);
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include <map>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef map<long long,long long> mp;
mp f;
long long N,M,V;
char inf[101],ouf[101];

int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr482.in%d",cani);
    sprintf(ouf,"mr482.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	N = M = V = 0;
	f.clear();
    scanf("%I64d%I64d%I64d",&N,&M,&V);
    for(int i = 1;i<=N;i++)
     for(int j = 1;j<=M;j++)
     {
      long long tmp;
      scanf("%I64d",&tmp);
      f[tmp] = f[tmp]+1;
     }
    f[1000000000] = 1;
    double ans = 0;
    long long s = 0;
    for(mp::iterator i = f.begin();i != f.end();i++)
    {
     long long tmp;
     if(i == f.begin()){
      s += (*i).second;
      continue;
     }
     mp::iterator j = --i;
     i++;
     tmp = s*((*i).first-(*j).first);
     s += (*i).second;
     if(V < tmp)
     {
      s-= (*i).second;
	 
      ans = double((*j).first)+double(V)/double(s);
		  break;
     }else
      V-= tmp;
    }
   
    printf("%.2f",ans);
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}

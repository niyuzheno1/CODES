#include <cstdlib>
#include <iostream>
#include <set>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#define itor iterator
#define Y second
#define X first
#define rep(i,n) for(int64 i = 0;i<n;i++)
#define rrep(i,n) for(int64 i = n-1;i>=0;i--)
using namespace std;
const int maxn=100010,maxm = 100001;
const int inf = 0x7f7f7f7f;
typedef long long int64;
typedef pair<int64,int64> pii;
typedef set<pii> sii;
sii si;
int64 H[maxn],n;
int64 d1[maxn][15];
int64 d2[maxn][15];
int64 sg1[maxn][15];
int64 sg2[maxn][15];
int main(int argc, char *argv[])
{
    scanf("%I64d",&n);
    rep(i,n)
     scanf("%I64d",&H[i]);
    rrep(i,n)
    {
     si.insert(pii(H[i],i));
     int delta1 = inf,n1 = -1;
     int delta2 = inf,n2 = -1;
     sii::itor it = find(si.begin(),si.end(),pii(H[i],i));
     if(it != si.begin()){
           it--;
     sii::itor u = si.begin();
     u--;
     for(; it != u;it--)
      if(abs((*it).X-H[i]) > delta2)
       break;
      else if( abs((*it).X-H[i]) < delta1 || (abs((*it).X-H[i]) == delta1 && (*it).X < H[n1]))
      {
       swap(delta2,delta1);swap(n1,n2);
       delta1 = abs((*it).X-H[i]);
       n1 = (*it).Y;
      }
      else if(abs((*it).X-H[i]) < delta2 || (abs((*it).X-H[i]) == delta2 && (*it).X < H[n2]))
      {
           delta2 = abs((*it).X-H[i]);
           n2 = (*it).Y;
      }
     }
     it = find(si.begin(),si.end(),pii(H[i],i));
     if(it != si.end()){
     it++;
     for(; it != si.end();it++)
      if(abs((*it).X-H[i]) > delta2)
       break;
      else if( abs((*it).X-H[i]) < delta1 || (abs((*it).X-H[i]) == delta1 && (*it).X < H[n1]))
      {
       swap(delta2,delta1);swap(n1,n2);
       delta1 = abs((*it).X-H[i]);
       n1 = (*it).Y;
      }
      else if(abs((*it).X-H[i]) < delta2 || (abs((*it).X-H[i]) == delta2 && (*it).X < H[n2]))
      {
           delta2 = abs((*it).X-H[i]);
           n2 = (*it).Y;
      }
     }
      d1[i][0] = n1;
      d2[i][0] = n2;
    }
    rep(i,n){
     if(H[d1[i][0]] != -1)
     sg1[i][0] = abs(H[d1[i][0]]-H[i]);
     if(H[d2[i][0]] != -1)
     sg2[i][0] = abs(H[d2[i][0]]-H[i]);
    }
    for(int j = 1;(1<<j)<=n;j++){
     rep(i,n){
      d1[i][j] = d2[d1[i][j-1]][j-1];
      d2[i][j] = d1[d2[i][j-1]][j-1];
      
     }
    }
    
    rep(i,n)
     printf("%I64d %I64d\n",d1[i][1],d2[i][1]);
    system("PAUSE");
    return EXIT_SUCCESS;
}

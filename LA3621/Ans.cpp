#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#define X first
#define Y second
#define  ser(m,i,x,y) for(m i = x;i != y ;i++)
#define  itor iterator
using namespace std;
typedef pair<int,int> pii;
typedef set<int> si;
int table[1010],cnt = 0;
si nes;
void dfs(int x,si a,int y)
{
    
    
    if(a.find(y) != a.end()){
     table[y] = min(table[y],x);
     return;
    }
    if(a.size() >= table[y])
     return;
    if(x == 2)
     x = 2;
    si n;
    ser(si::itor,i,a.begin(),a.end())
     ser(si::itor,j,a.begin(),a.end())
     {
      n = a;
      if((*i)-(*j) > 0 && (*i)-(*j) <= 1000 && table[(*i)-(*j)]>x){
       n.insert((*i)-(*j));
       dfs(x+1,n,y);
      }
      n = a;
      if((*i)+(*j) > 0 && (*i)+(*j) <= 1000 && table[(*i)+(*j)]>x){
       n.insert((*i)+(*j));
       dfs(x+1,n,y);
      }
     }
}
int main(int argc, char *argv[])
{
    memset(table,0x7f,sizeof(table));
    freopen("table","w",stdout);
    si so;
    so.insert(1);
    table[1] = 1;
    printf("{");
    for(int i = 2;i<=999;i++){
     
     dfs(1,so,i);
     printf("%d,",table[i]);
    }
    dfs(1,so,1000);
    printf("%d}",table[1000]);
    
    return EXIT_SUCCESS;
}

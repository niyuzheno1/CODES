#include "mode.h"
#define MN 31000
#undef INF
const int INF = ~0U>>1;
struct Edge{
       int top,a[MN],loc[MN*2],next[MN*2];
       void init(){
       CLEAR(a,0);
       top = 0;
       }
       void add(int x,int y){
       int p = ++top;
       loc[p] = y;
       next[p] = a[x];
       a[x] = p;
       }
};
Edge a,child;
int value[MN],depth[MN],father[MN],blockroot[MN];
int size[MN],limit;
int VSum[MN],VMax[MN];
void buildblocks(int v,int f,int dep){
 depth[v] = dep;
 father[v] = f;
 int curBlock = blockroot[v];
 for(int p= a.a[v];p;p=a.next[p])
  if(a.loc[p] != f)
  {
   if(size[curBlock]+1 < limit){
    child.add(v,a.loc[p]);
    blockroot[a.loc[p]] = curBlock;
    ++size[curBlock];
   }
   buildblocks(a.loc[p],v,dep+1);
  }
}
void initData(int v,int sumValue,int maxValue){
sumValue += value[v];VSum[v] = sumValue;
maxValue = max(maxValue,value[v]);VMax[v] = maxValue;
for(int p = child.a[v];p;p=child.next[p])
 initData(child.loc[p],sumValue,maxValue);
}
void Change(int v,int Data)
{
      value[v] = Data;
      if(v == blockroot[v]) initData(v,0,-INF);
      else initData(v,VSum[father[v]],VMax[father[v]]);
}
pii Query(int a,int b){
 pii ans(0,-INF);
 while(a != b){
 if(depth[a] < depth[b]) swap(a,b);
  if(blockroot[a] == blockroot[b])
  {
   ans.X += value[a];
   ans.Y = max(ans.Y,value[a]);
   a = father[a];
  }
  else{
   if(depth[blockroot[a]] < depth[blockroot[b]])
    swap(a,b);
   ans.X += VSum[a];
   ans.Y = max(ans.Y,VMax[a]);
   a = father[blockroot[a]];
  }
 }
 ans.X += value[a];
 ans.Y = max(ans.Y ,value[a]);
 return ans;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi;
    limit = sqrt(n)+1;
    a.init();child.init();
    for(int i = 1;i<n;++i)
    {
     int x = gi,y = gi;
     a.add(x,y);a.add(y,x);
    }
    for(int i = 1;i<=n;++i)
    {
     value[i] = gi;
     blockroot[i] = i;
    }
    CLEAR(size,0);
    buildblocks(1,0,0);
    for(int i = 1;i<=n;++i)
     if(blockroot[i] == i)
      initData(i,0,-INF);
    int m = gi;
    char cmd[20];
    for(int i = 0;i<m;++i)
    {
     int x,y;
     scanf("%s%d%d",cmd,&x,&y);
     pii ans;
     switch(cmd[1])
     {
      case 'M':ans = Query(x,y);printf("%d\n",ans.Y); break;
      case 'S':ans = Query(x,y);printf("%d\n",ans.X); break;
      case 'H':Change(x,y); break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}

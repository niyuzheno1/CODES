#include "mode.h"
#include "data.h"

int n,m;
const int N = 1000005;
int a[N];



pii maxs[N<<1];
int64 sum[N<<1];


void update(int l,int r){
 int u = getID(l,r),m=(l+r)>>1,lc = getID(l,m),rc = getID(m+1,r);
 sum[u] = sum[lc]+sum[rc];
 maxs[u] = max(maxs[lc],maxs[rc]);
}

void insert(int l,int r,int pos,int x){
 if(l == r){
  int u = getID(l,r);
  sum[u] = x;
  maxs[u] = MP(x,l);
 } else {
  int m = (l+r)>>1;
  if(pos <= m)
   insert(l,m,pos,x);
  else
   insert(m+1,r,pos,x);
  update(l,r);
 }
}

pair<int,int> getmax(int l,int r,int a,int b){
 if(a<=l && r<=b)
 {
  int u = getID(l,r);return maxs[u];
 }
 int m = (l+r)>>1;
 if(m < a)
  return getmax(m+1,r,a,b);
 else if(b <= m)
  return getmax(l,m,a,b);
 else
  return max(getmax(m+1,r,a,b),getmax(l,m,a,b));
}

int64 getans(int l,int r,int a,int b){
  if(b < l || r < a)
   return 0;
  if(a <= l && r <= b)
   return sum[getID(l,r)];
  int m = (l+r)>>1;
  return getans(l,m,a,b)+getans(m+1,r,a,b);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m=gi;
    for(int i = 0;i<n;++i)
     a[i] = gi,insert(0,n-1,i,a[i]);
    for(int i = 0,op;i<m;++i){
     op = gi;
     if(op ==  1){
      int l=gi,r=gi;
      --l,--r;
      printf("%I64d\n",getans(0,n-1,l,r));
     }
     else if(op == 2){
      int l=gi,r=gi,x=gi;
      --l,--r;
      int pos = 0;
      while(a[pos = getmax(0,n-1,l,r).Y] >= x){
       a[pos] %= x;
       insert(0,n-1,pos,a[pos]);
      }
     }else {
      int k=gi,x=gi;
      --k;
      a[k] = x;
      insert(0,n-1,k,x);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
